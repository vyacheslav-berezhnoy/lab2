#include "tournament.h"
void unique_triples(std::vector<std::shared_ptr<Prisoner>> &prisoners, int n, int rounds) {
    std::vector<std::shared_ptr<Prisoner>> current_game;
    std::vector<int> base;
    for (int c3 = 2; c3 < n; ++c3) {
        for (int c2 = 1; c2 < c3; ++c2) {
            for (int c1 = 0; c1 < c2; ++c1) {
                current_game.clear();
                base.clear();
                current_game.push_back(prisoners[c3]);
                base.push_back(prisoners[c3]->get_score());
                current_game.push_back(prisoners[c2]);
                base.push_back(prisoners[c2]->get_score());
                current_game.push_back(prisoners[c1]);
                base.push_back(prisoners[c1]->get_score());
                for (auto &x : current_game) {
                    x->clear_history();
                }
                
                for (int i = 0; i < rounds; ++i) {
                    get_decisions(current_game);
                    update_scores(current_game);
                }
                std::cout << "This game is between strategies " << c3 + 1 << ", " << c2 + 1 << " and " << c1 + 1 << std::endl;
                std::cout << "The score in this round:" << std::endl;
                std::cout << current_game[0]->get_score() - base[0] << " " << current_game[1]->get_score() - base[1] 
                                                        << " " << current_game[2]->get_score() - base[2] << std::endl;
                std::cout << std::endl;
            }
        }
    }
}
int get_n_competitors() {
    bool flag = false;
    std::string s;
    std::cin >> s;
    flag = is_number(s);
    while (!flag && (std::stoi(s) > 6)) {
        std::cout << "Not a valid number of competitors! Please try again." << std::endl;
        std::cin >> s;
        flag = is_number(s);
    }
    return std::stoi(s);
}
void tournament() {
    std::vector<std::shared_ptr<Prisoner>> prisoners;
    int max_count;
    std::cout << "Please choose how many strategies you want to take part in the tournament. Minimum is 3 and maximum is 6." << std::endl;
    max_count = get_n_competitors();
    std::cout << "Please choose the strategies you want to compete." << std::endl;
    std::cout << "Tough Tit for tat: 1" << std::endl;
    std::cout << "Tit for two tats: 2" << std::endl;
    std::cout << "Random: 3" << std::endl;
    std::cout << "Soft Tit for tat: 4" << std::endl;
    std::cout << "Go by majority: 5" << std::endl;
    std::cout << "Always defect: 6" << std::endl;
    int prisoner_count = 0;
    while (prisoner_count < max_count) {
        get_prisoners(prisoners, prisoner_count);
    }
    std::cout << "How many rounds do you want each game to be?" << std::endl;
    int rounds;
    rounds = get_iterations();
    unique_triples(prisoners, max_count, rounds);
    std::cout << "Game over!" << std::endl;
    std::cout << "Total score ";
    for (const auto &x: prisoners) {
        std::cout << x->get_score() << " ";
    }
    int max_ind = -1;
    int max = -1;
    for (int i = 0; i < max_count; ++i) {
        if (prisoners[i]->get_score() > max) {
            max = prisoners[i]->get_score();
            max_ind = i;
        }
    }
    std::cout << std::endl;
    std::cout << "And the winner is..." << std::endl;
    std::cout << "Strategy " << max_ind + 1 << "!" << std::endl;
}
