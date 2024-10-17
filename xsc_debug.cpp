#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int usage() {
    // Prints usage message (help)
    system("figlet XSC | lolcat");
    cout << "\neXtremelySimpleCalculator usage:\n"
    << "`xsc --help` for help\n"
    << "`xsc <number> <(+|-|*|/|%|^)> <number>` for basic operation calculating\n"
    << "`xsc -r|--sqrt <number>` for square root calculation\n";
    return 0;
}

int main(int argc, char* argv[]) {
    // main::Calculations();
    if (argv[1] == "-r" || argv[1] == "--sqrt") {
        int result = sqrt(atoi(argv[2]));
    }
    else {
        int result = atoi(argv[1]), argv[2], atoi(argv[3]);
    }

    // main::Handling();
    if (argv[1] == "--help" || argv[1] == "-h") {
        usage();
        return 0;
    }
    else if (argc > 4) {
        cout << "too many arguments!\n";
        usage();
        return 1;
    }
    else if (argc < 2) {
        cout << "not enough arguments!\n";
        usage();
        return 1;
    }
}
