package io.github.tuilakhanh.Lab05.RMIServer;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IMath extends Remote
{
    int add(int a, int b) throws RemoteException;
    int sub(int a, int b) throws RemoteException;
    int mul(int a, int b) throws RemoteException;
    int div(int a, int b) throws RemoteException;
    float[] PTBac2(float a, float b, float c) throws RemoteException;
}