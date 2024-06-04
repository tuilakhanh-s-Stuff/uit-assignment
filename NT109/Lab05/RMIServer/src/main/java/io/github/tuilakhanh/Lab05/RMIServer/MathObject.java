package io.github.tuilakhanh.Lab05.RMIServer;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MathObject extends UnicastRemoteObject implements IMath {
    public MathObject() throws RemoteException {
        super();
    }
    @Override
    public int add(int a, int b) throws RemoteException {
        return a+b;
    }
    @Override
    public int sub(int a, int b) throws RemoteException {
        return a-b;
    }
    @Override
    public int mul(int a, int b) throws RemoteException {
        return a*b;
    }
    @Override
    public int div(int a, int b) throws RemoteException {
        return a/b;
    }
    public float[] PTBac2(float a, float b, float c) throws RemoteException{

        float delta = b*b - 4*a*c;

        if (delta < 0) {
            throw new RemoteException("Phuong trinh khong co nghiem");
        }

        var x1 = (float) ((-b + Math.sqrt(delta)) / (2 * a));
        var x2 = (float) ((-b - Math.sqrt(delta)) / (2 * a));

        return new float[] {x1, x2};
    }
}