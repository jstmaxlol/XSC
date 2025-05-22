// escape.ansi.h (escape.ANSI.sux)
#pragma once

#include <string>

const std::string black   = "\033[30m";
const std::string red     = "\033[31m";
const std::string green   = "\033[32m";
const std::string yellow  = "\033[33m";
const std::string blue    = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan    = "\033[36m";
const std::string white   = "\033[37m";
const std::string def     = "\033[0m";

/* example syntax:
#include <iostream>
#include "escape.ansi.h"

int main() {
    std::cout << red << "this text is red, crazy scheisse!";
}

->  this is stupid but if you know a better way idk just tell me or drop a PR i will probably just merge it
*/
