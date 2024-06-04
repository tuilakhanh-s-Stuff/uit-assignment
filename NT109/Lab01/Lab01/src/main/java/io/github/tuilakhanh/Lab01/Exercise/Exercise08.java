package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Exercise08 {
    public static void Exercise08(Scanner scanner, Log log) {
        log.writeLog(String.format("Bai 08: So nguyen to co 5 chu so: %s", findPrimeWithFiveNum()));
    }

    static String findPrimeWithFiveNum() {
        var lowerLimit = 10000;
        var upperLimit = 99999;
        var primes = Exercise07.sieve(upperLimit);
        return IntStream.rangeClosed(lowerLimit, upperLimit)
                .filter(i -> primes[i])
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(", "));
    }
}
