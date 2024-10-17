#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/* void usage() {
    // Prints usage message (help)
    system("figlet XSC | lolcat");
    cout << "\neXtremelySimpleCalculator usage:\n"
    << "`xsc --help` for help\n"
    << "`xsc <number> <(+|-|*|/|%|^)> <number>` for basic operation calculating\n"
    << "`xsc -r|--sqrt <number>` for square root calculation\n";
} */

int main(int argc, char* argv[]) {
    if (argv[1] == "--help" || argv[1] == "-h") { /* usage(); */ return 0; }
    /*
    else if (argc > 4) {
        cout << "too many arguments!\n";
        // usage();
        return 1;
    }
    else if (argc < 2) {
        cout << "not enough arguments!\n";
        // usage();
        return 1;
    }    
    */
    else if (argv[2][0] == '+') { cout << atof(argv[1]) + atof(argv[3]); }
    else if (argv[2][0] == '-') { cout << atof(argv[1]) - atof(argv[3]); }
    else if (argv[2][0] == '*') { cout << atof(argv[1]) * atof(argv[3]); }
    else if (argv[2][0] == '/') { cout << atof(argv[1]) / atof(argv[3]); }
    else if (argv[2][0] == '%') { cout << fmod(atof(argv[1]), atof(argv[3])); }
    else if (argv[2][0] == '^') { cout << pow(atof(argv[1]), atof(argv[3]));  }
    else if (argv[1] == "-r" || argv[1] == "--sqrt") { cout << sqrt(atof(argv[2])); }
    
    return 0;
}
