#pragma once
#include "prisoner.h"
#include "factory.h"
class AlwaysDefect : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);
};
namespace {
    std::shared_ptr<Prisoner> CreateAlwaysDefect() {
        std::shared_ptr<AlwaysDefect> ret = std::make_shared<AlwaysDefect>();
        return ret; 
    }
    const int ALWAYSDEFECT = 6;
    const bool registered = Factory::Instance()->Register(ALWAYSDEFECT, CreateAlwaysDefect);
}