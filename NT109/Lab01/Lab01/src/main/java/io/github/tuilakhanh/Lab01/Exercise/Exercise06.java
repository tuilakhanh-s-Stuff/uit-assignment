package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Exercise06 {
    public static void Exercise06(Scanner scanner, Log log) {
        log.writeLog("Bai 06: Nhap a: ");
        var a = scanner.nextInt();
        log.writeLog("Bai 06: Nhap b: ");
        var b = scanner.nextInt();
        var gcd = Exercise06.findGCD(a, b);
        var lcm = Exercise06.findLCM(a, b, gcd);
        log.writeLog(String.format("Bai 06: A = %s, B = %s, GCD = %s, LCM = %s", a, b, gcd, lcm));
    }

    static int findGCD(int a, int b) {
        while (b != 0) {
            var temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    static int findLCM(int a, int b, int gcd) {
        return (a * b) / gcd;
    }
}
