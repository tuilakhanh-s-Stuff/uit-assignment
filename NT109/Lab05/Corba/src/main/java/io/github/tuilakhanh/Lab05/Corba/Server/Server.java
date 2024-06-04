package io.github.tuilakhanh.Lab05.Corba.Server;

import CalcApp.*;
import CalcApp.CalcPackage.DivisionByZero;
import org.omg.CosNaming.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import io.github.tuilakhanh.log.Log;

class CalcImpl extends CalcPOA {
    @Override
    public float sum(float a, float b) {
        return a + b;
    }
    @Override
    public float div(float a, float b) throws DivisionByZero {
        if (b == 0) {
            throw new CalcApp.CalcPackage.DivisionByZero();
        } else {
            return a / b;
        }
    }
    @Override
    public float mul(float a, float b) {
        return a * b;
    }
    @Override
    public float sub(float a, float b) {
        return a - b;
    }
}

public class Server {
    public static void main(String[] args) {
        Log log = new Log("configs/config.txt");
        try {
            // Initialize ORB and get references
            ORB orb = ORB.init(args, null);
            POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();

            // Create servant and register with POA
            CalcImpl calcImpl = new CalcImpl();
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(calcImpl);

            Calc href = CalcHelper.narrow(ref);
            NamingContextExt ncRef = NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));
            ncRef.rebind(ncRef.to_name("Calc"), href);

            log.writeLog("[Server] Calc Server ready and waiting ...");
            orb.run();
        } catch (Exception e) {
            System.err.println("[Server] ERROR: " + e);
            e.printStackTrace(System.out);
        }
        log.writeLog("[Server] Exiting ...");
    }
}