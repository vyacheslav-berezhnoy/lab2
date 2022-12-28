#include "fast.h"
void fast() {
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
    std::string iterations;
    int rounds;
    std::cout << "Choose the number of rounds" << std::endl;
    rounds = get_iterations();
    for (int i = 0; i < rounds; ++i) {
        get_decisions(prisoners);
        update_scores(prisoners);
    }
    std::cout << "Total score ";
    for (const auto &x: prisoners) {
        std::cout << x->get_score() << " ";
    }
    std::cout << std::endl;
}