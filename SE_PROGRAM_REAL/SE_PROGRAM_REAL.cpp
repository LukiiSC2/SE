#include <iostream>
#include <limits>
#include <cstdlib>
#include "InputN.h"
#include "InputPositiveStep.h"
#include "InputNegativeStep.h"
#include "Calculator.h"

void FinishScreen();
void ResultScreen(int n, double a, double b, double step);

void WelcomeScreen() {
    std::cout
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "| Welcome to our program dear user                             |\n"
        << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
        << "| Before calculation you must to input some data. Prepare them |\n"
        << "| If you ready for calculation press any button                |\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cin.get();
    system("cls");
}

void EndScreen() {
    std::cout
        << "Thank you for using our program\n"
        << "We hope that you have find your result\n"
        << "Goodbye \n\n\n\n\n\n";
    exit(0);
}

void CheckIfNotNumber() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("INPUT ONLY NUMBERS");
    }
}

int inputN() {
    while (true) {
        try {
            std::cout << "\nInput n >> ";
            double n;
            std::cin >> n;

            CheckIfNotNumber();

            int validated = ValidateN(n);

            system("cls");
            return validated;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
        
    }
}

double inputA() {
    std::cout << "\n\nInput the range of x (a,b)\n";

    while (true) {
        double a;
        try {
            std::cout << "\nInput a >> ";
            std::cin >> a;

            CheckIfNotNumber();

            system("cls");
            return a;
        }
        catch (const char* errorhandle) {
            std::cout << "ERROR " << errorhandle << "\n";
        }
    }
}

double inputB() {
    double b;
    while (true) {
        try {
            std::cout << "\nInput b >> ";
            std::cin >> b;

            CheckIfNotNumber();

            system("cls");
            return b;
        }
        catch (const char* errorhandle) { 
            std::cout << "ERROR " << errorhandle << "\n"; 
        }
    }
}

double inputStep(double a, double b) {
    double step;
    while (a < b) {
        try {
            std::cout << "\nInput step >> ";
            std::cin >> step;

            CheckIfNotNumber();

            double validated = ValidatenPositiveStep(step);
            system("cls");
            return step;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
    while (a > b) {
        try {
            std::cout << "\nInput step >> ";
            std::cin >> step;

            CheckIfNotNumber();

            double validate = ValidatenNegativeStep(step);
            system("cls");
            return step;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
    if (a == b) {
        std::cout
            << "Your step will be quale 1 because a = b \n\n\n\n";
        return 1;
    }
}

void AgreeScreen(int n, double a, double b, double step) {
    while (true) {
        try {
            std::cout
                << "Your n = " << n << "\n"
                << "Your range of x (" << a << "," << b << ")" << "\n"
                << "Your step = " << step << "\n"
                << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                << "| Press 0 if you want to close the program     |\n"
                << "| Press 1 if you want to restart inputing data |\n"
                << "| Press 2 if you agree with this data          |\n"
                << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                << ">> ";
            double temp;
            std::cin >> temp;

            CheckIfNotNumber();

            if (temp != 0 && temp != 1 && temp != 2) {
                throw "Input only 0, 1 or 2";
                continue;
            }
            system("cls");
            if (temp == 0) {
                EndScreen();
            }
            else if (temp == 1) return;
            else ResultScreen(n, a, b, step);
            return;
        }
        catch (const char* errorhandle) {
            std::cout << "ERROR " << errorhandle << "\n";
        }
    }
    system("cls");
}

void ResultScreen(int n, double a, double b, double step) {
    std::cout
        << "~~~~~~~~~~~~~~~~\n"
        << "| Your answers |\n"
        << "~~~~~~~~~~~~~~~~\n";
    if (a < b) {
        for (double x = a; x <= b; x = x + step) {
            //output answers if a < b
            std::cout << "Your x = " << x << "     Result = " << Calculator(x, n) << "\n";
        }
    }
    else if (a>b) {
        for (double x = a; x >= b; x = x + step) {
            //output answers if a > b 
            std::cout << "Your x = " << x << "     Result = " << Calculator(x, n) << "\n";
        }
    }
    else { std::cout << "Your x = " << a << "     Result = " << Calculator(a, n) << "\n"; }

    FinishScreen();
    return;
}

void FinishScreen() {
    short timeless;
    while (true) {
        try {
            std::cout
                << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                << "| Exit the program >> input 0        |\n"
                << "| Calculate other numbers >> input 1 | \n"
                << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                << ">> ";

            std::cin >> timeless;

            CheckIfNotNumber();

            if (timeless != 1 && timeless != 0) {
                throw "Input 1 or 2 please\n";
                continue;
            }

            if (timeless == 0) EndScreen();
            else if (timeless == 1) return;
        }
        catch (const char* errorhandle) {
            std::cout << "ERROR " << errorhandle << "\n";
        }
    }
}

int main() {
    WelcomeScreen();
    while (true) {
        int n;
        double a;
        double b;
        double step;
        n = inputN();
        a = inputA();
        b = inputB();
        step = inputStep(a, b);
        AgreeScreen(n, a, b, step);
    }
}

