#pragma once
#include <random>
#include "factory.h"
#include "prisoner.h"
class Random : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);
};

namespace {
    std::shared_ptr<Prisoner> CreateRandom() {
        std::shared_ptr<Random> ret = std::make_shared<Random>();
        return ret; 
    }
    const int RANDOM = 3;
    const bool registered = Factory::Instance()->Register(RANDOM, CreateRandom);
}