package io.github.tuilakhanh.Lab04;

import io.github.tuilakhanh.log.Log;

import java.util.Arrays;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int[] data = new Random().ints(2000, 0, 3000).toArray();
        int[] singleData = data.clone();
        int[] multiData = data.clone();

        Log log = new Log("configs/config.txt");

        long startTime = System.nanoTime();
        Thread singleThread = new Thread(new SingleThreadQuickSort(singleData, 0, data.length - 1));
        singleThread.start();
        try {
            singleThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        long endTime = System.nanoTime();
        long singleThreadTime = endTime - startTime;

        startTime = System.nanoTime();
        Thread multiThread = new Thread(new MultiThreadQuickSort(multiData, 0, data.length - 1));
        multiThread.start();
        try {
            multiThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        endTime = System.nanoTime();
        long multiThreadTime = endTime - startTime;

        // Print results
        log.writeLog(String.format("Array size: %s", data.length));
        log.writeLog(String.format("Single-threaded Quicksort Time: %sns\n", singleThreadTime));
        System.out.println(Arrays.toString(singleData));
        log.writeLog(String.format("Multi-threaded Quicksort Time: %sns\n", multiThreadTime));
        System.out.println(Arrays.toString(multiData));
    }
}