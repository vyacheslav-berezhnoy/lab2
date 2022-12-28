#include "prisoner.h"
int Prisoner::get_last() {
        return history[history.size() - 1];
}
void Prisoner::update_score(int x) {
    score += x;
    last_update = x;
}
int Prisoner::get_score_update() {
    return last_update;
}
char Prisoner::get_last_char() {
    if (get_last()) {return 'C';}
    return 'D';
}
int Prisoner::get_score() {
    return score;
}
void Prisoner::clear_history() {
    history.clear();
}
const std::vector<int>& Prisoner::get_history() {
    return history;
}