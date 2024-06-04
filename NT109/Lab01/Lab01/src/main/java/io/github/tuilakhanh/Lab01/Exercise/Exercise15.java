package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;
import java.util.regex.Pattern;

public class Exercise15 {

    public static void Exercise15(Scanner scanner, Log log) {
        var codes = new String[5];

        for (int i = 0; i < 5; i++) {
            do {
                log.writeLog(String.format("Bai 15: Nhap code thu %s: ", i));
                codes[i] = scanner.nextLine();
            } while (!isValidCode(codes[i]));
        }

        log.writeLog(String.format("Bai 15: Code da nhap: %s", String.join(", ", codes)));
    }

    static boolean isValidCode(String code) {
        return Pattern.matches("^00[2-5]L[0-9]{4}$", code);
    }
}
