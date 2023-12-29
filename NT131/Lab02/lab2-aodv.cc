/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


// Network topology
/*
                                      <--n3 
  (0s)   n0 -----300m------ n1
         n2 ->

                    ____n2_
              _____/       \_
             /               \            
    (20s)  n0 -----300m------ n1
             \_____         _/ 
                   \____  _/  
                        n3
*/
// - All links are wireless IEEE 802.11b with OLSR
// - n0 and n1 are currently out of range
// - UDP flow from n0 to n1
// - n3 moving from right to left
// - n2 moving from left to right
#include "ns3/aodv-module.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/mobility-module.h"
#include "ns3/wifi-module.h"
#include "ns3/olsr-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/mobility-module.h"
#include "myapp.h"

NS_LOG_COMPONENT_DEFINE ("Lab2");

using namespace ns3;

// Mobility model for node2 & node3
Ptr<ConstantVelocityMobilityModel> cvmm2;
Ptr<ConstantVelocityMobilityModel> cvmm3;
double position_interval = 1.0;


void stopMover()
{
  cvmm2 -> SetVelocity(Vector(0,0,0));
  cvmm3 -> SetVelocity(Vector(0,0,0));
}

void
ReceivePacket(Ptr<const Packet> p, const Address & addr)
{
   std::cout << Simulator::Now ().GetSeconds () << "\t" << p->GetSize() <<"\n";
}


int main (int argc, char *argv[])
{
  bool enableFlowMonitor = false;
  std::string phyMode ("DsssRate1Mbps");

  CommandLine cmd;
  cmd.AddValue ("EnableMonitor", "Enable Flow Monitor", enableFlowMonitor);
  cmd.AddValue ("phyMode", "Wifi Phy mode", phyMode);
  cmd.Parse (argc, argv);

//
// Explicitly create the nodes required by the topology (shown above).
//
  NS_LOG_INFO ("Create nodes.");
  NodeContainer c; // ALL Nodes
  c.Create(4);
  

  // Set up WiFi
  WifiHelper wifi;

  YansWifiPhyHelper wifiPhy;
  wifiPhy.SetPcapDataLinkType (YansWifiPhyHelper::DLT_IEEE802_11);

  YansWifiChannelHelper wifiChannel;
  // disable fragmentation for frames below 2200 bytes
  // Config::SetDefault ("ns3::WifiRemoteStationManager::FragmentationThreshold", StringValue ("2200"));
  // turn off RTS/CTS for frames below 2200 bytes
  // Config::SetDefault ("ns3::WifiRemoteStationManager::RtsCtsThreshold", StringValue ("2200"));
        
  wifiChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
  //wifiChannel.AddPropagationLoss ("ns3::TwoRayGroundPropagationLossModel",
//	  	  	  	  	  	  	  	    "SystemLoss", DoubleValue(1),
//		  	  	  	  	  	  	    "HeightAboveZ", DoubleValue(1.5));
  wifiChannel.AddPropagationLoss("ns3::ThreeLogDistancePropagationLossModel");
     
  // For a range
  wifiPhy.Set ("TxPowerStart", DoubleValue(14));
  wifiPhy.Set ("TxPowerEnd", DoubleValue(14));
  wifiPhy.Set ("TxPowerLevels", UintegerValue(1));
  wifiPhy.Set ("TxGain", DoubleValue(0));
  wifiPhy.Set ("RxGain", DoubleValue(0));
   

  wifiPhy.SetChannel (wifiChannel.Create ());

  // Add a non-QoS upper mac
  WifiMacHelper wifiMac;
  wifiMac.SetType ("ns3::AdhocWifiMac");

  // Set 802.11b standard
  wifi.SetStandard (WIFI_STANDARD_80211b);

  wifi.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
                                "DataMode",StringValue(phyMode),
                                "ControlMode",StringValue(phyMode));


  NetDeviceContainer devices;
  devices = wifi.Install (wifiPhy, wifiMac, c);


  //  Enable AODV

 AodvHelper aodv;
 OlsrHelper olsr;
  // Install the routing protocol
  Ipv4ListRoutingHelper list;
  list.Add (aodv, 10);

  // Set up internet stack
  InternetStackHelper internet;
  internet.SetRoutingHelper (list);
  internet.Install (c);


  // Set up Addresses
  Ipv4AddressHelper ipv4;
  NS_LOG_INFO ("Assign IP Addresses.");
  ipv4.SetBase ("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer ifcont = ipv4.Assign (devices);


  NS_LOG_INFO ("Create Applications.");

  // UDP connfection from N0 to N2

  uint16_t sinkPort = 9;
  Address sinkAddress (InetSocketAddress (ifcont.GetAddress (1), sinkPort)); // interface of n2
  PacketSinkHelper packetSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
  ApplicationContainer sinkApps = packetSinkHelper.Install (c.Get (1)); //n2 as sink
  sinkApps.Start (Seconds (0.));
  sinkApps.Stop (Seconds (100.));

  Ptr<Socket> ns3UdpSocket = Socket::CreateSocket (c.Get (0), UdpSocketFactory::GetTypeId ()); //source at n0

  // Create UDP application at n0
  Ptr<MyApp> app = CreateObject<MyApp> ();
  app->Setup (ns3UdpSocket, sinkAddress, 1040, 100000, DataRate ("250Kbps"));
 //Ptr<MyApp> app1 = CreateObject<MyApp> ();
  //app1->Setup (ns3UdpSocket, sinkAddress, 2000, 100000, DataRate ("1000Kbps"));

  c.Get (0)->AddApplication (app);
  //c.Get (0)->AddApplication (app1);
  
  //app1->SetStartTime (Seconds (10.));
  //app1->SetStopTime (Seconds (40.));

  app->SetStartTime (Seconds (1.));
  app->SetStopTime (Seconds (40.));

  // Set Mobility for all nodes

  MobilityHelper mobility;
  Ptr<ListPositionAllocator> positionAlloc = CreateObject <ListPositionAllocator>();
  positionAlloc ->Add(Vector(0, 0, 0)); // node0
  positionAlloc ->Add(Vector(350, 0, 0)); // node1 
  positionAlloc ->Add(Vector(0, 110, 0)); // node2
  positionAlloc ->Add(Vector(150, 0, 0)); // node3
  
  Ptr<Node> mover2 = c.Get(2);
  Ptr<Node> mover3 = c.Get(3);

  mobility.SetPositionAllocator(positionAlloc);

  Vector vel2 (8, 0, 0);
  Vector vel3 (0, -15, 0);
 

  mobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
  mobility.Install(c);
  cvmm2 = mover2->GetObject<ConstantVelocityMobilityModel> ();
  cvmm2->SetVelocity(vel2);
  cvmm3 = mover3->GetObject<ConstantVelocityMobilityModel> ();
  cvmm3->SetVelocity(vel3);
  
  // Trace Received Packets
  Config::ConnectWithoutContext("/NodeList/*/ApplicationList/*/$ns3::PacketSink/Rx", MakeCallback (&ReceivePacket));

  // Trace devices (pcap)
  wifiPhy.EnablePcap ("lab2-aodv-dev0", devices.Get(0));
  wifiPhy.EnablePcap ("lab2-aodv-dev1", devices.Get(1));
  wifiPhy.EnablePcap ("lab2-aodv-dev2", devices.Get(2));
  wifiPhy.EnablePcap ("lab2-aodv-dev3", devices.Get(3));
  // Flow Monitor
  Ptr<FlowMonitor> flowmon;
  FlowMonitorHelper flowmonHelper;
  flowmon = flowmonHelper.InstallAll ();
 

  //
  // Now, do the actual simulation.
  //
  NS_LOG_INFO ("Run Simulation.");
  Simulator::Schedule(Seconds(40), &stopMover);
  Simulator::Stop (Seconds(40.));
  Simulator::Run ();

  flowmon->CheckForLostPackets ();

  Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmonHelper.GetClassifier ());
  std::map<FlowId, FlowMonitor::FlowStats> stats = flowmon->GetFlowStats ();
  for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator i = stats.begin (); i != stats.end (); ++i)
   {
	  Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (i->first);
      if ((t.sourceAddress=="10.1.1.1" && t.destinationAddress == "10.1.1.2"))
      {
          std::cout << "Flow " << i->first  << " (" << t.sourceAddress << " -> " << t.destinationAddress << ")\n";
          std::cout << "  Tx Bytes:   " << i->second.txBytes << "\n";
          std::cout << "  Rx Bytes:   " << i->second.rxBytes << "\n";
      	  std::cout << "  Throughput: " << i->second.rxBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds())/1024/1024  << " Mbps\n";
      }
   }

  //flowmon->SerializeToXmlFile("lab3.flowmon", true, true);
  Simulator::Destroy ();
  NS_LOG_INFO ("Done.");
}