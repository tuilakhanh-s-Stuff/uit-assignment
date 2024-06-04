package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Exercise09 {

    public static void Exercise09(Scanner scanner, Log log) {
        log.writeLog("Bai 09: Nhap so nguyen n: ");
        var n = scanner.nextInt();
        log.writeLog(String.format("Bai 09: So nguyen n = %s, Phan tich: %s", n, findPrimeFactorization(n)));
    }
    static String findPrimeFactorization(int n) {
        var upperLimit = n;
        var isPrime = Exercise07.sieve(upperLimit);

        var primeFactors = new ArrayList<Integer>();

        while (n > 1) {
            for (int i = 2; i <= upperLimit; i++) {
                if (isPrime[i] && n % i == 0) {
                    n /= i;
                    primeFactors.add(i);
                    break;
                }
            }
        }

        return primeFactors.stream()
                .map(String::valueOf)
                .collect(Collectors.joining("x"));
    }
}
