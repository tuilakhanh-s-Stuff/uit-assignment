package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;
import java.util.stream.Stream;

public class Exercise10 {
    public static void Exercise10(Scanner scanner, Log log) {
        log.writeLog("Bai 10: Nhap chuoi: ");
        var s = scanner.nextLine();
        log.writeLog(String.format("Bai 10: Chuoi: %s, co %s ky tu", s, countWords(s)));
    }

    static long countWords(String s) {
        return Stream.of(s.split("\\s+"))
                .count();
    }
}
