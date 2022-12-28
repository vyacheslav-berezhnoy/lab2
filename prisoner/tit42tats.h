#pragma once 
#include "prisoner.h"
#include "factory.h"
class Tit42Tats : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);

private:
    int counter = 0;
};

namespace {
    std::shared_ptr<Prisoner> CreateTit42Tats() {
        std::shared_ptr<Tit42Tats> ret = std::make_shared<Tit42Tats>();
        return ret; 
    }
    const int TIT42TATS = 2;
    const bool registered = Factory::Instance()->Register(TIT42TATS, CreateTit42Tats);
}