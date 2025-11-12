#include <iostream>
int main()
{
    int Hi = 1;
    short process = 1;
    while (process == 1) {
        int n;
        double a;
        double b;
        double step;
        int choice = 2;

        //Welcome screen
        if (Hi == 1) {
            Hi++;
            std::cout
                << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                << "| Welcome to our program dear user                             |\n"
                << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
                << "| Before calculation you must to input some data. Prepare them |\n"
                << "| If you ready for calculation press any button                |\n"
                << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cin.get();
            system("cls");
        }



        //get and check n
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
            break;
        }

        std::cout << "\n\nInput the range of x (a,b)\n";

        //get and check range of x
        while (true) {
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
            break;
        }

        while (true) {
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
            break;
        }

        //get and check step
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
            break;
        }
        while (a > b) {
            std::cout << "\nInput step >> ";
            std::cin >> step;

            (std::cin.fail()); {
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
            break;
        }
        if (a == b) {
            step = 1;
            std::cout
                << "Your step will be quale 1 because a = b \n\n\n\n";
        }


        std::cout
            << "Your n = " << n << "\n"
            << "Your step = " << step << "\n"
            << "Your range of x (" << a << "," << b << ")" << "\n"
            << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            << "| Press any buton if you agree with this data  |\n"
            << "| Press 1 if you want to restart inputing data |\n"
            << "| Press 2 if you want to close the program     |\n"
            << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            << ">> ";

        int timeless;
        std::cin >> timeless;
        system("cls");


        if (timeless == 2) {
            std::cout
                << "Thank you for using our program\n"
                << "We hope that you have find your resuld\n"
                << "Goodbye\n\n\n\n\n\n";
            process = 2;
            break;
        }

        else if (timeless == 1) continue;

        else {

            process = 0;

            std::cout
                << "~~~~~~~~~~~~\n"
                << "| Your answers |\n"
                << "~~~~~~~~~~~~\n";
            //check a < b or no
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
                            j = j++;
                            if (j <= n);
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
                            j = j++;
                            if (j <= n);
                        }
                    }
                    //output answers if a > b
                    std::cout << "Your x = " << x << "     Result = " << mlt << "\n";
                }
            }

            //asking for finish or continue
            while (true) {

                std::cout
                    << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                    << "| Calculate other numbers >> input 1 |\n"
                    << "| Exit the program >> input 2        | \n"
                    << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                    << ">> ";

                std::cin >> process;

                if (std::cin.fail()) {
                    std::cout << "Input 1 or 2 please\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (process != 1 && process != 2) {
                    std::cout << "Input 1 or 2 please\n";
                    continue;
                }
                break;
            }
        }
        if (process == 2) {
            system("cls");
            std::cout
                << "Thank you for using our program\n"
                << "We hope that you have find your result\n"
                << "Goodbye\n\n\n\n\n\n"; break;
        }

    }
}

