#include <iostream>
#include <cmath>
using namespace std;

void usage() {
    // Prints usage message (help)
    system("figlet XSC | lolcat");
    cout << "\neXtremelySimpleCalculator usage:\n"
    << "`xsc --help | -h` for help\n"
    << "`xsc <number> <(+|-|*|/|%|^)> <number>`\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1 && (argv[1] == "--help" || argv[1] == "-h")) {
        usage();
        return 0;
    }
    else {
        if (argc > 1 && argv[2][0] == '+') { cout << atof(argv[1]) + atof(argv[3]); }
        else if (argv[2][0] == '-') { cout << atof(argv[1]) - atof(argv[3]); }
        else if (argv[2][0] == '*') { cout << atof(argv[1]) * atof(argv[3]); }
        else if (argv[2][0] == '/') { cout << atof(argv[1]) / atof(argv[3]); }
        else if (argv[2][0] == '%') { cout << fmod(atof(argv[1]), atof(argv[3])); }
        else if (argv[2][0] == '^') { cout << pow(atof(argv[1]), atof(argv[3]));  }
    }
    return 0;
}
