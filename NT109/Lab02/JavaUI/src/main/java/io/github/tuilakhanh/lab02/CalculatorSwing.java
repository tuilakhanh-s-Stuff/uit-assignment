package io.github.tuilakhanh.lab02;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorSwing extends JFrame implements ActionListener {
    double num1;
    char operator;

    private JPanel mainPanel;
    private JButton MCButton;
    private JButton MRButton;
    private JButton MSButton;
    private JButton mButton;
    private JButton mButton1;
    private JButton backspaceButton;
    private JButton CEButton;
    private JButton cButton;
    private JButton button9;
    private JButton button10;
    private JButton a7Button;
    private JButton a8Button;
    private JButton a9Button;
    private JButton divButton;
    private JButton percentButton;
    private JButton a4Button;
    private JButton a5Button;
    private JButton a6Button;
    private JButton mulButton;
    private JButton a1XButton;
    private JButton a1Button;
    private JButton a2Button;
    private JButton a3Button;
    private JButton subButton;
    private JButton equalButton;
    private JButton a0Button;
    private JButton commaButton;
    private JButton plusButton;
    private JTextArea display;

    public CalculatorSwing() {
        super("Calculator");
        setVisible(true);
        var menuBar = new MenuBar();
        setMenuBar(menuBar);
        menuBar.add(new Menu("View"));
        menuBar.add(new Menu("Edit"));
        menuBar.add(new Menu("Help"));
//        display.setAlignmentX(TextArea.LEFT_ALIGNMENT);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.equals("1/x")) {
            if (display.getText().isEmpty())
                return;
            try {
                double num = Double.parseDouble(display.getText());
                if (num == 0) {
                    return;
                }
                double result = 1 / num;
                display.setText(String.valueOf(result));
                num1 = result;
            } catch (NumberFormatException ex) {
                display.setText("Error");
            }
        }
        else if (Character.isDigit(command.charAt(0))) {
            display.setText(display.getText() + command);
        } else if (command.equals(".")) {
            display.setText(display.getText() + ".");
        } else if (command.equals("C") || command.equals("CE")) {
            display.setText("");
            num1 = 0;
            operator = '\0';
        } else if (command.equals("±")) {
            String currentText = display.getText();
            if (currentText.startsWith("-")) {
                display.setText(currentText.substring(1));
            } else {
                display.setText("-" + currentText);
            }
        } else if (command.equals("√")) {
            try {
                double num = Double.parseDouble(display.getText());
                double result = Math.sqrt(num);
                display.setText(String.valueOf(result));
            } catch (NumberFormatException ex) {
                display.setText("Error");
            }
        } else if (command.equals("=")) {
            calculate();
        } else if (command.equals("<-")) {
            String currentText = display.getText();
            if (!currentText.isEmpty()) {
                display.setText(currentText.substring(0, currentText.length() - 1));
            }
        }
        else {
            if (display.getText().isEmpty())
                return;
            if (operator == '\0') {
                num1 = Double.parseDouble(display.getText());
            } else {
                calculate();
            }
            display.setText("");
            operator = command.charAt(0);

        }
    }

    private void calculate() {
        double num2 = Double.parseDouble(display.getText());
        double result;
        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    display.setText("Error: Division by zero");
                    return;
                }
                result = num1 / num2;
                break;
            default:
                display.setText("Error: Invalid operation");
                return;
        }
        if (result % 1.0 == 0) {
            int intResult = (int) result;
            display.setText(String.valueOf(intResult));
        } else {
            display.setText(String.valueOf(result));
        }
        num1 = result;
        operator = '\0';
    }
}
