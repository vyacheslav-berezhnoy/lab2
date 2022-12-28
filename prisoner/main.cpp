#include <iostream>
#include <string>
#include <cstring>
#include "detailed.h"
#include "fast.h"
#include "tournament.h"
void getmode();
int main() {
    getmode();
}
void getmode() {
    std::string mode;
    std::cout << "Please choose the game mode. F for fast, D for detailed, T for tournament" << std::endl;
    std::cin >> mode;
    for (auto & c: mode) c = toupper(c);
    if (mode == "F") {
        fast();
    }
    else if (mode == "D") {
        detailed();
    }
    else if (mode == "T") {
        tournament();
    }
    else {
        std::cout << "Not a valid game mode! Please try again" << std::endl;
        getmode();
    }
}