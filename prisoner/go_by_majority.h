#pragma once
#include "prisoner.h"
#include "factory.h"
class GoByMajority : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);
};
namespace {
    std::shared_ptr<Prisoner> CreateGoByMajority() {
        std::shared_ptr<GoByMajority> ret = std::make_shared<GoByMajority>();
        return ret; 
    }
    const int GOBYMAJORITY = 5;
    const bool registered = Factory::Instance()->Register(GOBYMAJORITY, CreateGoByMajority);
}