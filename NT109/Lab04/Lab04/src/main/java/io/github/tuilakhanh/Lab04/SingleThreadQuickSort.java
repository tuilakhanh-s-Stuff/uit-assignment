package io.github.tuilakhanh.Lab04;

public class SingleThreadQuickSort implements Runnable {
    private final int[] arr;
    private final int low;
    private final int high;

    public SingleThreadQuickSort(int[] arr, int low, int high) {
        this.arr = arr;
        this.low = low;
        this.high = high;
    }

    @Override
    public void run() {
        QuickSort.quickSort(arr, low, high);
    }
}
