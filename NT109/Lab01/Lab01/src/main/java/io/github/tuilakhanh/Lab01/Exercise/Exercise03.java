package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.HashMap;
import java.util.Scanner;

public class Exercise03 {
    public static void Exercise03(Scanner scanner, Log log) {
        log.writeLog("Bai 03: Nhap so nguyen n: ");
        var n = scanner.nextInt();
        log.writeLog(String.format("Bai 03: So nguyen n = %s, map(i, i*i) = %s", n, MapIxI(n)));
    }

    static String MapIxI(int n) {
        var map = new HashMap<Integer, Integer>();
        for (int i = 1; i <= n; i++) {
            map.put(i, i * i);
        }
        return map.toString();
    }
}
