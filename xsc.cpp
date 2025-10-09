#include <iostream>
#include <string>
#include <cmath>

// github.com/jstmaxlol/escape.ANSI.sux
#include "escape.ansi"

int calculate(double& n1, char& op, double& n2);
void usage();

int main(int argc, char** argv) {
    if (argc > 5) {
        std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "too_many_arguments " << def;
        return -1;
    }
    if (argc < 2) {
        std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "not_enough_arguments " << def;
        return -1;
    }

    std::string arg1 = argv[1];

    // help
    if (arg1 == "help" || arg1 == "h") {
        usage();
        return 0;
    }
    if (arg1 == "--help" || arg1 == "-h") {
        std::cerr << "::> " << red << "xsc.Warning" << def << "/" << red << "non_existing_argument\n"
                  << def << "::> did you mean: " << yellow << "h" << def << " || " << yellow << "help" << def << "?\n";
        usage();
        return -1;
    }

    // square root: xsc <num> r
    if (argc == 3) {
        double n1;
        try {
            n1 = std::stod(arg1);
        } catch (...) {
            std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "invalid_number " << def;
            return -1;
        }
        std::string opstr = argv[2];
        if (opstr == "r") {
            std::cout << sqrt(n1) << std::endl;
            return 0;
        } else {
            std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "invalid_operator " << def;
            return -1;
        }
    }

    // normal operation: xsc <num1> <op> <num2>
    if (argc == 4) {
        double n1, n2;
        char op;
        try {
            n1 = std::stod(arg1);
            n2 = std::stod(argv[3]);
        } catch (...) {
            std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "invalid_number " << def;
            return -1;
        }
        op = argv[2][0];
        return calculate(n1, op, n2);
    }

    // if only 1 argument and not help
    std::cerr << "::> " << red << "xsc.Error" << def << "/" << red << "not_enough_arguments " << def;
    return -1;
}

int calculate(double& n1, char& op, double& n2) {
    switch (op) {
        case '+':
            std::cout << n1 + n2 << "\n";
            return 0;
        case '-':
            std::cout << n1 - n2 << "\n";
            return 0;
        case 'x':
            std::cout << n1 * n2 << "\n";
            return 0;
        case '/':
            if (n2 == 0) {
                std::cerr << "::> " << red << "xsc.MathError" << def << "/" << red << "divsion_by_zero";
                return -1;
            }
            std::cout << n1 / n2 << "\n";
            return 0;
        case '%':
            std::cout << (n1 / n2) * 100 << "\n";
            return 0;
        case '^':
            std::cout << pow(n1, n2) << "\n";
            return 0;
    }
    return -1;
}

void usage() {
    // Prints usage message (help)
	system("figlet XSC | lolcat"); // TODO: fallback if figlet & lolcat are not installed (not needed for aur users, so is it useful?)
    std::cout
    << "[ eXtremelySimpleCalculator usage screen ]\n\n"

    << "'xsc help / h'                          | print usage screen (this one!)\n"
    << "'xsc <num1> <(+|-|x|/|%|^)> <num2>'     | outputs expression's result\n"
    << "'xsc <num1> r'                          | outputs the square root of num1\n"
    ;
}
