package io.github.tuilakhanh.Lab04;

public class MultiThreadQuickSort implements Runnable {
    private static final int NUM_THREADS = 4;

    private final int[] arr;
    private final int low;
    private final int high;

    public MultiThreadQuickSort(int[] arr, int low, int high) {
        this.arr = arr;
        this.low = low;
        this.high = high;
    }

    @Override
    public void run() {
        if (low < high) {
            int pivotIndex = QuickSort.partition(arr, low, high);

            if (Thread.activeCount() < NUM_THREADS) {
                new Thread(new MultiThreadQuickSort(arr, low, pivotIndex - 1)).start();
            } else {
                QuickSort.quickSort(arr, low, pivotIndex - 1);
            }

            QuickSort.quickSort(arr, pivotIndex + 1, high);
        }
    }
}

