package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Exercise07 {
    public static void Exercise07(Scanner scanner, Log log) {
        log.writeLog("Bai 07: Nhap so nguyen n: ");
        var n = scanner.nextInt();
        log.writeLog(String.format("Bai 07: n = %s, Cac so nguyen to nho hon n: %s", n, findPrimeNumSmaller(n)));
    }

    public static boolean[] sieve(int n) {
        var isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    static String findPrimeNumSmaller(int n) {
        var primes = sieve(n);
        return IntStream.rangeClosed(2, n)
                .filter(i -> primes[i])
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(", "));
    }
}
