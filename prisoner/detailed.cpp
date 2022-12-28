#include "detailed.h"

void print_log(std::vector<std::shared_ptr<Prisoner>> &prisoners) {
    std::cout << "Choices this round: ";
    for (const auto &x: prisoners) {
        std::cout << x->get_last_char() << " ";
    }
    std::cout << std::endl;
    std::cout << "Score this round ";
    for (const auto &x: prisoners) {
        std::cout << x->get_score_update() << " ";
    }
    std::cout << std::endl;
    std::cout << "Total score ";
    for (const auto &x: prisoners) {
        std::cout << x->get_score() << " ";
    }
    std::cout << std::endl;
}
void detailed() {
    std::vector<std::shared_ptr<Prisoner>> prisoners;
    std::cout << "Please choose the strategies you want to compete." << std::endl;

    std::cout << "Tough Tit for tat: 1" << std::endl;
    std::cout << "Tit for two tats: 2" << std::endl;
    std::cout << "Random: 3" << std::endl;
    std::cout << "Soft Tit for tat: 4" << std::endl;
    std::cout << "Go by majority: 5" << std::endl;
    std::cout << "Always defect: 6" << std::endl;
    int prisoner_count = 0;
    while (prisoner_count < 3) {
        get_prisoners(prisoners, prisoner_count);
    }
    char test = 'a';
    while (test != 'q') {
        std::cout << "Press 'q' if you want to exit. Press any other key to continue." << std::endl;
        get_decisions(prisoners);
        update_scores(prisoners);
        print_log(prisoners);
        std::cin >> test;
    }
}