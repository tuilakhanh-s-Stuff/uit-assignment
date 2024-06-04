package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Exercise02 {
    public static void Exercise02(Scanner scanner, Log log) {
        log.writeLog("Bai 2: Nhap so nguyen n: ");
        var n = scanner.nextLong();
        log.writeLog(String.format("Bai 02: So nguyen n = %s, Factorial = %s", n, Fractorial(n)));
    }
    static long Fractorial(long n) {
        return n < 0 ? Long.MIN_VALUE : (n == 0) ? 1 : n * Fractorial(n - 1);
    }
}
