#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void clear() {
    // Clears the screen
    system("clear");
}
void usage() {
    // Prints usage message (help)
    clear();
    system("figlet XSC | lolcat");
    cout << "\neXtremelySimpleCalculator usage:\n"
    << "`xsc --help` for help\n"
    << "`xsc <number> <(+|-|*|/|%|^)> <number>` for basic operation calculating\n"
    << "`xsc -r|--sqrt <number>` for square root calculation\n";
}

int doOper(int n1, char opx[], int n2) {
    // Performs calculations, TODO: improve :)
    int result;
    switch (opx[1]) {
       case '+':
          result = n1 + n2;
          break;
       case '-':
          result = n1 - n2;
          break;
       case '*':
          result = n1 * n2;
          break;
       case '/':
          result = n1 / n2;
          break;
       case '%':
          result = n1 % n2;
          break;
       case '^':
          result = pow(n1, n2);
          break;
        case 'sqrt':
          result = sqrt(n1);
       default:
          cout << "invalid operator!\n";
          break;
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Main handler
    if (argc > 1) {
        if (argv[1] == "--help" || argv[1] == "-h") {
            usage();
            return 0;
        }
        else if (argv[1] == "-r" || argv[1] == "--sqrt") {
            if (argc > 2) {
                int n1 = stoi(argv[2]);
                int result =doOper(n1, argv[1], 0);
                cout << n1 << " "  << argv[1] << " = " << result << "\n";
                return 0;
            }
            else if (argc < 3) {
                cout << "too many arguments!\n";
                usage();
                return 0;
            }
            else if (argc < 2) {
                cout << "too few arguments!\n";
                usage();
                return 0;
            }
            else {
                cout << "invalid argument!\n";
                usage();
                return 0;
            }
        }
        else {
            if (argc < 3) {
                int n1 = stoi(argv[1]);
                int n2 = stoi(argv[3]);
                int result = doOper(n1, argv[2], n2);
                cout << n1 << " "  << argv[1] << " " << n2 << " = " << result << "\n";
                return 0;
            }
            else if (argc > 3) {
                cout << "too many arguments!\n";
                usage();
                return 0;
            }
            else if (argc < 3) {
                cout << "too few arguments!\ndid you want to calculate a square root? use --sqrt\n";
                usage();
                return 0;
            }
            else {
                cout << "invalid argument; << " << argv[1] << " >> \n";
                usage();
                return 0;
            }
        }
    }
}
