#include <iostream>
#include <limits>

void FinishScreen();
void EndScreen();
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

int inputN() {
    int n;
    while (true) {
        std::cout << "\nInput n >> ";
        double timeless;
        std::cin >> timeless;

        if (std::cin.fail()) {
            std::cout
                << "\n###################### \n"
                << "# INPUT ONLY NUMBERS #\n"
                << "###################### \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        n = timeless;

        if (n != timeless) {
            std::cout
                << "\n#######################\n"
                << "# Input only integers #\n"
                << "#######################\n";
            continue;
        }

        if (n <= 1) {
            std::cout
                << "\n########################\n"
                << "# Input n which is > 1 #\n"
                << "########################\n";
            continue;
        }
        system("cls");
        return n;

    }
}

double inputA() {
    std::cout << "\n\nInput the range of x (a,b)\n";

    while (true) {
        double a;
        std::cout << "\nInput a >> ";
        std::cin >> a;

        if (std::cin.fail()) {
            std::cout
                << "\n###################### \n"
                << "# INPUT ONLY NUMBERS #\n"
                << "###################### \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        system("cls");
        return a;
    }
}

double inputB() {
    while (true) {
        double b;
        std::cout << "\nInput b >> ";
        std::cin >> b;
        if (std::cin.fail()) {
            std::cout
                << "\n###################### \n"
                << "# INPUT ONLY NUMBERS #\n"
                << "###################### \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        system("cls");
        return b;
    }
}

double inputStep(double a, double b) {
    double step;
    while (a < b) {
        std::cout << "\nInput step >> ";
        std::cin >> step;

        if (std::cin.fail()) {
            std::cout
                << "\n###################### \n"
                << "# INPUT ONLY NUMBERS #\n"
                << "###################### \n \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (step <= 0) {
            std::cout
                << "\n###########################\n"
                << "# Input step which is > 0 #\n"
                << "###########################\n";
            continue;
        }
        system("cls");
        return step;
    }
    while (a > b) {
        std::cout << "\nInput step >> ";
        std::cin >> step;

        if (std::cin.fail()) {
            std::cout
                << "\n###################### \n"
                << "# INPUT ONLY NUMBERS #\n"
                << "###################### \n \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }


        if (step >= 0) {
            std::cout
                << "\n###########################\n"
                << "# Input step which is < 0 #\n"
                << "###########################\n";
            continue;
        }
        system("cls");
        return step;
    }
    if (a == b) {
        std::cout
            << "Your step will be quale 1 because a = b \n\n\n\n";
        return 1;
    }
}

void AgreeScreen(int n, double a, double b, double step) {
    while (true) {
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
        double timeless;
        std::cin >> timeless;

        if (std::cin.fail()) {
            std::cout
                << "\n####################### \n"
                << "# INPUT ONLY 0,1 or 2 #\n"
                << "####################### \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (timeless != 0 && timeless != 1 && timeless != 2) {
            std::cout
                << "\n########################\n"
                << "# Input only 0, 1 or 2 #\n"
                << "########################\n";
            continue;
        }
        system("cls");
        if (timeless == 0) {
            EndScreen();
        }
        else if (timeless == 1) return;
        else ResultScreen(n, a, b, step);
    }
    system("cls");
}

void EndScreen() {
    std::cout
        << "Thank you for using our program\n"
        << "We hope that you have find your resuld\n"
        << "Goodbye\n\n\n\n\n\n";
    exit(0);
}

void ResultScreen(int n, double a, double b, double step) {
    std::cout
        << "~~~~~~~~~~~~~~~~\n"
        << "| Your answers |\n"
        << "~~~~~~~~~~~~~~~~\n";
    if (a < b) {
        for (double x = a; x <= b; x = x + step) {
            double mlt = 1;
            if (x < 0) {
                double i = 1;
                while (i <= n) {
                    mlt = mlt * (x + 2) / (i - x);
                    i++;
                }
            }
            else {
                int j = 1;
                while (j <= n) {
                    double sum = 0;
                    int i = 1;
                    while (i <= (n + 1)) {
                        sum = sum + 3 * x + ((i + x) / (i * j));
                        i++;
                    }
                    mlt = mlt * sum;
                    j++;
                }
            }

            //output answers if a < b
            std::cout << "Your x = " << x << "     Result = " << mlt << "\n";
        }
    }
    else {
        for (double x = a; x >= b; x = x + step) {
            double mlt = 1;
            if (x < 0) {
                double i = 1;
                while (i <= n) {
                    mlt = mlt * (x + 2) / (i - x);
                    i++;
                }
            }
            else {
                int j = 1;
                while (j <= n) {
                    double sum = 0;
                    int i = 1;
                    while (i <= (n + 1)) {
                        sum = sum + 3 * x + ((i + x) / (i * j));
                        i++;
                    }
                    mlt = mlt * sum;
                    j++;
                }
            }
            //output answers if a > b
            std::cout << "Your x = " << x << "     Result = " << mlt << "\n";
        }
    }
    FinishScreen();
}

void FinishScreen() {
    short timeless;
    while (true) {


        std::cout
            << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            << "| Exit the program >> input 0        |\n"
            << "| Calculate other numbers >> input 1 | \n"
            << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            << ">> ";

        std::cin >> timeless;

        if (std::cin.fail()) {
            std::cout << "Input 1 or 2 please\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (timeless != 1 && timeless != 0) {
            std::cout << "Input 1 or 2 please\n";
            continue;
        }

        if (timeless == 0) EndScreen();
    }
}

int main() {
    short process = 1;
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

