package io.github.tuilakhanh.Lab01;

import io.github.tuilakhanh.Lab01.Utils.Menu;
import io.github.tuilakhanh.log.Log;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var log = new Log("config.txt");
        var scanner = new Scanner(System.in);
        var menu = new Menu(scanner, log);
        var choice = 0;
        do {
            choice = menu.displayMenu();
            menu.handleChoice(choice);
        } while (choice != 0);
        scanner.close();
    }
}