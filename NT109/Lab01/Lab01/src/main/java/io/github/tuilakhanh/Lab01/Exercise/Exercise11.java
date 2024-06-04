package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Exercise11 {
    public static void Exercise11(Scanner scanner, Log log) {
        log.writeLog("Bai 11: Nhap chuoi: ");
        var s = scanner.nextLine();
        log.writeLog(String.format("Bai 11: Chuoi: %s, Co so lan xuat hien cac tu: %s", s, countWordOccurrences(s)));
    }

    static String countWordOccurrences(String s) {
        return Stream.of(s.split("\\s+"))
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
                .entrySet()
                .stream()
                .map(entry -> String.format("%s = %s", entry.getKey(), entry.getValue()))
                .collect(Collectors.joining(", ")); // Join entries with newline
    }
}
