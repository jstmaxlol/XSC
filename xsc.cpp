#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void usage() {
    // Prints usage message (help)
    system("figlet XSC | lolcat");
    cout << "\neXtremelySimpleCalculator usage:\n"
    << "`xsc --help | -h` for help\n"
    << "`xsc <number> <(+|-|x|/|%|^)> <number>` for mathematical operation\n"
    << "`xsc -sqrt | -r <number>` for square root operation\n"
    << "\n[n!] `xsc` doesn't support mathematical expressions (to-do)\n";
}

int main(int argc, char* argv[]) {
    // AAAAAAAAAA (a.k.a. argument validation and execution)
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--sqrt" || arg == "-r") {
            if (i + 1 < argc) {
                double num = stod(argv[i + 1]);
                cout << sqrt(num) << "\n";
                return 0;
            }
            else {
                cout << "[e!] invalid input!\n";
                usage();
                return 1;
            }
        }
        else if (arg == "--help" || arg == "-h") {
            usage();
            return 0;
        }
        else if (i + 2 < argc) {
            string op = argv[i + 1];
            double num1 = stod(argv[i]);
            double num2 = stod(argv[i + 2]);
            double result;

            if (op == "+") {
                result = num1 + num2;
            }
            else if (op == "-") {
                result = num1 - num2;
            }
            else if (op == "x") {
                result = num1 * num2;
            }
            else if (op == "/") {
                if (num2 != 0) {
                    result = num1 / num2;
                }
                else {
                    cout << "[math_e!] division by zero!\n";
                    usage();
                    return 1;
                }
            }
            else if (op == "%") {
                result = fmod(num1, num2);
            }
            else if (op == "^") {
                result = pow(num1, num2);
            }
            else {
                cout << "[e!] invalid operator!\n";
                usage();
                return 1;
            }
            // show result :)
            cout << result << "\n";
            return 0;
        }
        else {
            cout << "[e!] invalid input!\n";
            usage();
            return 1;
        }

    }

    return 0;
}
