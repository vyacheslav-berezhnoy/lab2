#include "always_defect.h"
void AlwaysDefect::decision(const std::vector<int>&, const std::vector<int>&) {
    if (!history.size()) {
        history.push_back(1);
        return;
    }
    history.push_back(0);
}