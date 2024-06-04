package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Exercise01 {
    public static void Exercise01(Log log) {
        log.writeLog(String.format("Bai 01: %s", findNum()));
    }

    static String findNum() {
        return IntStream.rangeClosed(10, 200)
                .filter(i -> i % 7 == 0 && i % 5 != 0)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(", "));
    }
}
