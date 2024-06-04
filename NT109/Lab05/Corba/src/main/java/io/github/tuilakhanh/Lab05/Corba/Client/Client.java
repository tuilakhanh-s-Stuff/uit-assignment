package io.github.tuilakhanh.Lab05.Corba.Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import CalcApp.*;
import CalcApp.CalcPackage.DivisionByZero;
import io.github.tuilakhanh.log.Log;
import org.omg.CosNaming.*;
import org.omg.CORBA.*;

public class Client {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Log log = new Log("configs/config.txt");
    public static void main(String[] args) {
        try {
            ORB orb = ORB.init(args, null);
            NamingContextExt ncRef = NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));
            Calc calcImpl = CalcHelper.narrow(ncRef.resolve_str("Calc"));

            label:
            while (true) {
                log.writeLog("[Client] 1. Sum");
                log.writeLog("[Client] 2. Sub");
                log.writeLog("[Client] 3. Mul");
                log.writeLog("[Client] 4. Div");
                log.writeLog("[Client] 5. exit");
                log.writeLog("[Client] --");
                System.out.print("[Client] Choice: ");
                try {
                    String opt = br.readLine();
                    switch (opt) {
                        case "5":
                            break label;
                        case "1":
                            log.writeLog("[Client] a + b = " + calcImpl.sum(getFloat("a"),
                                    getFloat("b")));
                            break;
                        case "2":
                            log.writeLog("[Client] a - b = " + calcImpl.sub(getFloat("a"),
                                    getFloat("b")));
                            break;
                        case "3":
                            log.writeLog("[Client] a * b = " + calcImpl.mul(getFloat("a"),
                                    getFloat("b")));
                            break;
                        case "4":
                            try {
                                log.writeLog("[Client] a / b = " +
                                        calcImpl.div(getFloat("a"), getFloat("b")));
                            } catch (DivisionByZero de) {
                                log.writeLog("[Client] Division by zero!!!");
                            }
                            break;
                    }
                } catch (Exception e) {
                    log.writeLog("[Client] ERROR : " + e);
                    e.printStackTrace(System.out);
                }
            }
            //calcImpl.shutdown();
        } catch (Exception e) {
            log.writeLog("[Client] ERROR : " + e);
            e.printStackTrace(System.out);
        }
    }

    static float getFloat(String number) throws Exception {
        log.writeLog(number + ": ");
        return Float.parseFloat(br.readLine());
    }
}