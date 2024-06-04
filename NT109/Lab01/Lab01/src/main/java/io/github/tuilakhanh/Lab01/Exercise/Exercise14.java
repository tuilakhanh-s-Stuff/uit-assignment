package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Exercise14 {
    record Largest(int largest, int rowIndex, int colIndex) {}
    public static void Exercise14(Scanner scanner, Log log) {
        log.writeLog("Bai 14: Nhap so dong: ");
        var n = scanner.nextInt();
        log.writeLog("Bai 14: Nhap so cot: ");
        var m = scanner.nextInt();

        var matrix = new int[n][m];
        log.writeLog("Bai 14: Nhap phan tu cua ma tran: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                do {
                    log.writeLog(String.format("Nhap phan tu tai %sx%s: ", i, j));
                    matrix[i][j] = scanner.nextInt();
                } while (matrix[i][j]  < 1 || matrix[i][j]  > 99);
            }
        }
        log.writeLog("Bai 14: Ma tran sau khi nhap: ");
        log.writeLog(printMatrix(matrix));

        Largest resultA = findLargest(matrix);
        log.writeLog(String.format("Bai 14: Phan tu lon nhat: %s, tai vi tri %sx%s", resultA.largest, resultA.rowIndex, resultA.colIndex));

        var primeMatrix = primeMatrix(matrix);
        log.writeLog("Bai 14: Ma tran voi phan nguyen to:");
        log.writeLog(printMatrix(primeMatrix));

        sortColumns(matrix);
        log.writeLog("Bai 14: Ma tran da duoc sap xep theo thu tu tang dan cua cot:");
        log.writeLog(printMatrix(matrix));

        log.writeLog(String.format("Bai 14: Cot co nhieu so nguyen to nhat: %s", findMostPrimeCol(matrix)));
    }

    static String printMatrix(int[][] matrix) {
        return "\n" + Arrays.stream(matrix)
                .map(row -> String.join(" ", Arrays.stream(row)
                                .mapToObj(String::valueOf)
                                .collect(Collectors.toList())
                        )
                )
                .collect(Collectors.joining("\n"));
    }

    static Largest findLargest(int[][] matrix) {
        var largest = Integer.MIN_VALUE;
        int rowIndex = -1, colIndex = -1;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] > largest) {
                    largest = matrix[i][j];
                    rowIndex = i;
                    colIndex = j;
                }
            }
        }
        return new Largest(largest, rowIndex, colIndex);
    }

    static int[][] primeMatrix(int[][] matrix) {
        var primeMatrix = new int[matrix.length][matrix[0].length];
        var isPrime = Exercise07.sieve(100);
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (!isPrime[matrix[i][j]]) {
                    primeMatrix[i][j] = 0;
                }
                else {
                    primeMatrix[i][j] = matrix[i][j];
                }
            }
        }
        return primeMatrix;
    }

    static void sortColumns(int[][] matrix) {
        for (int col = 0; col < matrix[0].length; col++) {
            var column = new ArrayList<Integer>();
            for (int row = 0; row < matrix.length; row++) {
                column.add(matrix[row][col]);
            }
            column.sort(Comparator.naturalOrder());
            for (int row = 0; row < matrix.length; row++) {
                matrix[row][col] = column.get(row);
            }
        }
    }

    static int findMostPrimeCol(int[][] matrix) {
        var isPrime = Exercise07.sieve(100);
        var primeCount = new int[matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (isPrime[matrix[i][j]]) {
                    primeCount[j]++;
                }
            }
        }
        return Arrays.stream(primeCount)
                .max()
                .getAsInt();
    }
}
