#include "go_by_majority.h"
void GoByMajority::decision(const std::vector<int>&x, const std::vector<int>&y) {
    if (!history.size()) {
        history.push_back(1);
        return;
    }
    int size1, size2, total_size;
    size1 = x.size();
    size2 = y.size();
    total_size = size1 + size2;
    int total_sum;
    total_sum = 0;
    for (int i = 0; i < size1; ++i) {
        total_sum += x[i];
        total_sum += y[i];
    }
    if (total_size - total_sum > total_sum) {
        history.push_back(0);
    }
    else {
        history.push_back(1);
    }
}