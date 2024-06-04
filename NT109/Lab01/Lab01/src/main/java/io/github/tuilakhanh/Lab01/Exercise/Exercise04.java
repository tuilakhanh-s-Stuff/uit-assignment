package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Exercise04 {
    public static void Exercise04(Scanner scanner, Log log) {
        log.writeLog("Bai 04: Nhap so thap phan: ");
        var num = scanner.nextInt();
        int base;
        do {
            System.out.print("Bai 04: Nhap he co so B (2 <= B <= 32): ");
            base = scanner.nextInt();
        } while (base < 2 || base > 32);
        log.writeLog(String.format("Bai 04: So thap phan = %s, Co so = %s, KQ = %s", num, base, toBase(num, base)));
    }

    static String toBase(int num, int base) {
        if (base < 2 || base > 32) {
            throw new IllegalArgumentException("Base khong hop le: " + base);
        }

        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            int digit = num % base;
            char digitChar = digit < 10 ? (char) ('0' + digit) : (char) ('A' + digit - 10);
            sb.append(digitChar);
            num /= base;
        }
        return sb.reverse().toString();
    }
}
