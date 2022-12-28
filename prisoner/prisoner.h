#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
class Prisoner {
protected:
    int score = 0;
    int last_update;
    std::vector<int> history; // 1 - cooperate, 0 - defect
public:
    int get_last();
    void update_score(int x);
    virtual void decision(const std::vector<int>&, const std::vector<int>&) = 0;
    int get_score_update();
    char get_last_char();
    int get_score();
    void clear_history();
    const std::vector<int>& get_history();
};
typedef std::shared_ptr<Prisoner> (*CreatePrisoner)();