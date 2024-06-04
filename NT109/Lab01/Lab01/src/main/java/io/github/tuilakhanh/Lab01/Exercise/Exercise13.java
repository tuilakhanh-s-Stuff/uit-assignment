package io.github.tuilakhanh.Lab01.Exercise;

import io.github.tuilakhanh.log.Log;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Exercise13 {
    record TwoLargest(int firstElement, int firstIndex, int secondElement, int secondIndex) {}

    public static void Exercise13(Scanner scanner, Log log) {
        log.writeLog("Bai 13: Nhap so phan tu cua mang: ");
        var n = scanner.nextInt();
        var A = new int[n];

        log.writeLog("Bai 13: Nhap " + n + " phan tu (so nguyen lon hon 0 va nho hon 100):");
        for (int i = 0; i < n; i++) {
            do {
                log.writeLog("Nhap phan tu thu " + i + ": ");
                A[i] = scanner.nextInt();
            } while (A[i] < 1 || A[i] > 99);
        }

        log.writeLog(String.format("Bai 13: Mang A: %s", printArray(A)));

        var largest = findTwoLargest(A);
        log.writeLog(String.format("Bai 13: Phan tu lon nhat la %s tai vi tri %s", largest.firstElement, largest.firstIndex));
        log.writeLog(String.format("Bai 13: Phan tu lon thu hai la %s tai vi tri %s", largest.secondElement, largest.secondIndex()));

        Arrays.sort(A);
        log.writeLog(String.format("Bai 13: Mang A sau khi sap xep: %s", printArray(A)));

        log.writeLog("Bai 13: Nhap so nguyen x muon them vao mang: ");
        var x = scanner.nextInt();
        log.writeLog(String.format("Bai 13: Mang A sau khi them x: %s", printArray(insertElement(A, x))));
    }

    static String printArray(int[] A) {
        return Arrays.stream(A)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(", "));
    }

    static TwoLargest findTwoLargest(int[] A) {
        int firstIndex = 0, secondIndex = -1;
        int first = A[0], second = Integer.MIN_VALUE;

        for (int i = 1; i < A.length; i++) {
            if (A[i] > first) {
                second = first;
                secondIndex = firstIndex;
                first = A[i];
                firstIndex = i;
            } else if (A[i] > second && A[i] != first) {
                second = A[i];
                secondIndex = i;
            }
        }

        return new TwoLargest(first, firstIndex, second, secondIndex);
    }

    static int[] insertElement(int[] A, int x) {
        int insertIndex = Arrays.binarySearch(A, x);
        if (insertIndex < 0) {
            insertIndex = -(insertIndex + 1);
        }

        int[] inserted = new int[A.length + 1];
        System.arraycopy(A, 0, inserted, 0, insertIndex);
        inserted[insertIndex] = x;
        System.arraycopy(A, insertIndex, inserted, insertIndex + 1, A.length - insertIndex);
        return inserted;
    }
}
