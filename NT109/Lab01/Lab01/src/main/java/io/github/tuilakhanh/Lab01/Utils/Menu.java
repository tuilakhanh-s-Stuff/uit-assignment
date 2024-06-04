package io.github.tuilakhanh.Lab01.Utils;

import io.github.tuilakhanh.Lab01.Exercise.*;
import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Menu {
    private Scanner scanner;

    private Log log;

    public Menu(Scanner scanner, Log log) {
        this.scanner = scanner;
        this.log = log;
    }

    public int displayMenu() {
        var menu = new StringBuffer();
        menu.append("\nMenu:\n");
        menu.append("01. Bai 01: Tim tat ca cac so chia het cho 7 nhung khong phai boi so cua 5 tu 10 den 200\n");
        menu.append("02. Bai 02: Tinh Giai thua cua so n\n");
        menu.append("03. Bai 03: Tinh map(i, i*i)\n");
        menu.append("04. Bai 04: Chuyen doi so thap phan sang he co so B\n");
        menu.append("05. Bai 05: In ra N so Fibonacci dau tien\n");
        menu.append("06. Bai 06: Tim UCLN va BCLN cua a va b\n");
        menu.append("07. Bai 07: In ra cac so nguyen to nho hon n\n");
        menu.append("08. Bai 08: Tim so nguyen to co 5 chu so\n");
        menu.append("09. Bai 09: Phan tich so nguyen n thanh cac thua so nguyen to\n");
        menu.append("10. Bai 10: Dem so ky tu trong chuoi\n");
        menu.append("11. Bai 11: Dem so lan xuat hien cac tu trong chuoi\n");
        menu.append("12. Bai 12: Kiem tra s1 co phai la xau con cua s2 khong\n");
        menu.append("13. Bai 13: Xu ly mang\n");
        menu.append("14. Bai 14: Xu ly ma tran\n");
        menu.append("15. Bai 15: Nhap code\n");
        menu.append("0 Thoat\n");
        menu.append("Nhap lua chon: ");
        log.writeLog(menu.toString());
        int choice = scanner.nextInt();
        scanner.nextLine();
        return choice;
    }

    public void handleChoice(int choice) {
        switch (choice) {
            case 1 -> Exercise01.Exercise01(log);
            case 2 -> Exercise02.Exercise02(scanner, log);
            case 3 -> Exercise03.Exercise03(scanner, log);
            case 4 -> Exercise04.Exercise04(scanner, log);
            case 5 -> Exercise05.Exercise05(scanner, log);
            case 6 -> Exercise06.Exercise06(scanner, log);
            case 7 -> Exercise07.Exercise07(scanner, log);
            case 8 -> Exercise08.Exercise08(scanner, log);
            case 9 -> Exercise09.Exercise09(scanner, log);
            case 10 -> Exercise10.Exercise10(scanner, log);
            case 11 -> Exercise11.Exercise11(scanner, log);
            case 12 -> Exercise12.Exercise12(scanner, log);
            case 13 -> Exercise13.Exercise13(scanner, log);
            case 14 -> Exercise14.Exercise14(scanner, log);
            case 15 -> Exercise15.Exercise15(scanner, log);
            case 0 -> log.writeLog("Exiting program...");
            default -> log.writeLog("Invalid choice. Please try again.");
        }
    }
}