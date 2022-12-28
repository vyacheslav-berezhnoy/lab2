#include "tit42tats.h"
void Tit42Tats::decision(const std::vector<int>&x, const std::vector<int>&y) {
    if (!history.size()) {
        history.push_back(1);
        return;
    }
    int size1, size2;
    size1 = x.size();
    size2 = y.size();
    auto a = x[size1-1];
    auto b = y[size2-1];

    if (a == 0 || b == 0) {
        counter++;
        if (counter > 1) {
            history.push_back(0);
        }
        else {
            history.push_back(1);
        }
    }
    else {
        counter = 0;
        history.push_back(1);
    }
}