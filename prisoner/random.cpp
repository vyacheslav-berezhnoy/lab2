#include "random.h"
void Random::decision(const std::vector<int>&, const std::vector<int>&) {
    if (!history.size()) {
        history.push_back(1);
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    float r = dis(gen);
    if (r < 0.5) {
        history.push_back(1);
    }
    else {
        history.push_back(0);
    }
}