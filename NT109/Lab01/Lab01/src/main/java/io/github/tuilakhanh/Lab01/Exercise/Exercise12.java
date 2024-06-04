package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Exercise12 {
    public static void Exercise12(Scanner scanner, Log log) {
        log.writeLog("Bai 12: Nhap chuoi s1: ");
        var s1 = scanner.nextLine();
        log.writeLog("Bai 12: Nhap chuoi s2: ");
        var s2 = scanner.nextLine();
        log.writeLog(String.format("Bai 11: Chuoi s1: %s, Chuoi s2: %s, %s", s1, s2, isStringContain(s1, s2)));
    }

    public static String isStringContain(String s1, String s2) {
        return s2.contains(s1) ? "s1 co chua s2" : "s1 khong chua s2";
    }
}
