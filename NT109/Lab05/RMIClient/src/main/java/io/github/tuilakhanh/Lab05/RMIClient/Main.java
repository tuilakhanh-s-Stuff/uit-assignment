package io.github.tuilakhanh.Lab05.RMIClient;

import io.github.tuilakhanh.Lab05.RMIServer.IMath;
import io.github.tuilakhanh.log.Log;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;


class CalculatorUI extends Frame implements ActionListener {
    Label display;
    Button[] buttons;
    MenuBar menuBar;

    double num1;
    char operator;

    IMath imath = (IMath) Naming.lookup("rmi://localhost/Service");

    Log log = new Log("configs/config.txt");

    public CalculatorUI() throws MalformedURLException, NotBoundException, RemoteException {
        super("Calculator");
        setLayout(new BorderLayout());

        createComponents();
        layoutComponents();

        setMenuBar(menuBar);
    }

    private void createComponents() {
        display = new Label();
        display.setAlignment(Label.RIGHT);
        display.setBackground(Color.WHITE);

        menuBar = new MenuBar();

        String[] buttonLabels = {"MC", "MR", "MS", "M+", "M-",
                "<-", "CE", "C", "±", "√",
                "7", "8", "9", "/", "%",
                "4", "5", "6", "*", "1/x",
                "1", "2", "3", "-",
                "0", ".", "+", "="};

        buttons = new Button[buttonLabels.length];
        for (int i = 0; i < buttonLabels.length; i++) {
            buttons[i] = new Button(buttonLabels[i]);
            buttons[i].addActionListener(this);
        }
    }

    private void layoutComponents() {
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints c = new GridBagConstraints();
        setLayout(layout);

        c.fill = GridBagConstraints.BOTH;
        c.gridwidth = 5;
        c.gridx = 0;
        c.gridy = 0;
        layout.setConstraints(display, c);
        add(display);

        c.gridwidth = 1;
        for (int i = 0; i < 24; i++) {
            int row = i / 5;
            int col = i % 5;
            c.gridx = col;
            c.gridy = row + 1;
            layout.setConstraints(buttons[i], c);
            add(buttons[i]);
        }

        c.gridwidth = 2;
        c.gridx = 0;
        c.gridy = 6;
        layout.setConstraints(buttons[24], c);
        add(buttons[24]);

        c.gridwidth = 1;
        c.gridx = 2;
        c.gridy = 6;
        layout.setConstraints(buttons[25], c);
        add(buttons[25]);

        c.gridwidth = 1;
        c.gridx = 3;
        c.gridy = 6;
        layout.setConstraints(buttons[26], c);
        add(buttons[26]);

        c.gridwidth = 1;
        c.gridheight= 4;
        c.gridx = 4;
        c.gridy = 4;
        layout.setConstraints(buttons[27], c);
        add(buttons[27]);

        menuBar.add(new Menu("View"));
        menuBar.add(new Menu("Edit"));
        menuBar.add(new Menu("Help"));
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
                double result = imath.div(1, (int) num1);
                log.writeLog(String.format("1 + %s = %s", num1, result));
                display.setText(String.valueOf(result));
                num1 = result;
            } catch (NumberFormatException ex) {
                display.setText("Error");
            } catch (RemoteException ex) {
                throw new RuntimeException(ex);
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
            try {
                calculate();
            } catch (RemoteException ex) {
                throw new RuntimeException(ex);
            }
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
                try {
                    calculate();
                } catch (RemoteException ex) {
                    throw new RuntimeException(ex);
                }
            }
            display.setText("");
            operator = command.charAt(0);

        }
    }

    private void calculate() throws RemoteException {
        double num2 = Double.parseDouble(display.getText());
        double result;
        switch (operator) {
            case '+':
                result = imath.add((int) num1, (int) num2);
                log.writeLog(String.format("%s + %s = %s", num1, num2, result));
                break;
            case '-':
                result = imath.sub((int) num1, (int) num2);
                log.writeLog(String.format("%s - %s = %s", num1, num2, result));
                break;
            case '*':
                result = imath.mul((int) num1, (int) num2);
                log.writeLog(String.format("%s * %s = %s", num1, num2, result));
                break;
            case '/':
                if (num2 == 0) {
                    display.setText("Error: Division by zero");
                    return;
                }
                result = imath.div((int) num1, (int) num2);
                log.writeLog(String.format("%s / %s = %s", num1, num2, result));
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

public class Main {
    public static void main(String[] args) throws MalformedURLException, NotBoundException, RemoteException {
        var frame = new CalculatorUI();
        frame.pack();
        frame.setVisible(true);
    }
}