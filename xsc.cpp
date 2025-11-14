#include <iostream>
#include <print>
#include <string>
#include <cmath>

// github.com/jstmaxlol/escape.ANSI.sux
#include "escape.ansi"

int calculate(double& n1, char& op, double& n2);
void usage();

int main(int argc, char** argv) {
    if (argc > 5) {
        std::print("::> {}xsc.Error{}/{}too_many_arguments{}\n", red, def, red, def);
        return 1;
    }
    if (argc < 2) {
        std::print("::> {}xsc.Error{}/{}not_enough_arguments{}\n", red, def, red, def);
        return 1;
    }

    std::string arg1 = argv[1];

    // help
    if (arg1 == "help" || arg1 == "h") {
        usage();
        return 0;
    }
    if (arg1 == "--help" || arg1 == "-h") {
        std::print("::> {}xsc.Warning{}/{}non_existing_argument{}\n", red, def, red, def);
        std::print("::> did you mean: {}h{} || {}help{}?\n", yellow, def, yellow, def);
        usage();
        return 1;
    }

    // square root: xsc <num> r
    if (argc == 3) {
        double n1;
        try {
            n1 = std::stod(arg1);
        } catch (...) {
            std::print("::> {}xsc.Error{}/{}invalid_number{}\n", red, def, red, def);
            return 1;
        }
        std::string opstr = argv[2];
        if (opstr == "r") {
            std::print("{}\n", sqrt(n1));
            return 0;
        } else {
            std::print("::> {}xsc.Error{}/{}invalid_operator{}\n", red, def, red, def);
            return 1;
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
            std::print("::> {}xsc.Error{}/{}invalid_number{}\n", red, def, red, def);
            return 1;
        }
        op = argv[2][0];
        return calculate(n1, op, n2);
    }

    // if only 1 argument and not help
    // TODO: remove this shit because it *is* redundant(, right?)
    std::print("::> {}xsc.Error{}/{}not_enough_arguments{}\n", red, def, red, def);
    return 1;
}

int calculate(double& n1, char& op, double& n2) {
    switch (op) {
        case '+': {
            std::cout << n1 + n2 << "\n";
            return 0;
        }
        case '-': {
            std::cout << n1 - n2 << "\n";
            return 0;
        }
        case 'x': {
            std::cout << n1 * n2 << "\n";
            return 0;
        }
        case '/': {
            if (n2 == 0) {
                std::print("::> {}xsc.MathError{}/{}division_by_zero{}\n", red, def, red, def);
                return 1;
            }
            std::cout << n1 / n2 << "\n";
            return 0;
        }
        case '%': {
            std::cout << (n1 / n2) * 100 << "\n";
            return 0;
        }
        case '^': {
            std::cout << pow(n1, n2) << "\n";
            return 0;
        }
    }
    return 1;
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
