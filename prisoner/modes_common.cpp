#include "modes_common.h"
bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int get_iterations() {
    bool flag = false;
    std::string s;
    std::cin >> s;
    flag = is_number(s);
    while (!flag) {
        std::cout << "Not a valid number of rounds! Please try again." << std::endl;
        std::cin >> s;
        flag = is_number(s);
    }
    return std::stoi(s);
}
void update_scores(std::vector<std::shared_ptr<Prisoner>> &prisoners) {
    int total = 0;
    for (const auto &x : prisoners) {
        total += x->get_last();
    }
    switch (total) {
        case 3:
            for (auto &x: prisoners) {
                x->update_score(7);
            }
            break;
        
        case 2:
            for (auto &x: prisoners) {
                if (x->get_last()) {
                    x->update_score(3);
                }
                else {
                    x->update_score(9);
                }
            }
            break;
        case 1:
            for (auto &x: prisoners) {
                if (!(x->get_last())) {
                    x->update_score(5);
                }
                else {
                    x->update_score(0);
                }
            }
            break;
        case 0:
            for (auto &x: prisoners) {
                x->update_score(1);
            }
            break;
    }

}
void get_decisions(std::vector<std::shared_ptr<Prisoner>> &prisoners) {
    auto history0 = prisoners[0]->get_history();
    auto history1 = prisoners[1]->get_history();
    auto history2 = prisoners[2]->get_history();
    prisoners[0]->decision(history1, history2);
    prisoners[1]->decision(history0, history2);
    prisoners[2]->decision(history0, history1);
}
void get_prisoners(std::vector<std::shared_ptr<Prisoner>> &prisoners, int &count) {
    std::string choice;
    std::cin >> choice;
    std::vector<std::string> choices = {"1", "2", "3", "4", "5", "6"};
    for (const auto &x :choices) {
        if (choice == x) {
            prisoners.push_back(Factory::Instance()->CreateObject(std::stoi(choice)));
            count++;
            return;
        }
    }
    std::cout << "Not a valid strategy ID. Please try again" << std::endl;
}