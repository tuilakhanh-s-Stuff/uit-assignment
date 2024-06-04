package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.HashMap;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

public class Exercise05 {
    static HashMap<Long, Long> memo = new HashMap<>();

    public static void Exercise05(Scanner scanner, Log log) {
        log.writeLog("Bai 05: Nhap so nguyen n: ");
        var n = scanner.nextInt();
        log.writeLog(String.format("Bai 05: so nguyen n = %s, N so Fibonacci dau tien: %s", n, findFirstNFibonacci(n)));
    }

    static long fibonacci(long n) {
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        if (n <= 1) {
            return n;
        } else {
            var result = fibonacci(n - 1) + fibonacci(n - 2);
            memo.put(n, result);
            return result;
        }
    }

    static String findFirstNFibonacci(int n) {
        return LongStream.rangeClosed(0, n)
                .map(Exercise05::fibonacci)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(", "));

    }
}
