#pragma once
#include "prisoner.h"
#include "factory.h"
class Tough_Tit4Tat : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);
};
namespace {
    std::shared_ptr<Prisoner> CreateTough_Tit4Tat() {
        std::shared_ptr<Tough_Tit4Tat> ret = std::make_shared<Tough_Tit4Tat>();
        return ret; 
    }
    const int TOUGH_TIT4TAT = 1;
    const bool registered = Factory::Instance()->Register(TOUGH_TIT4TAT, CreateTough_Tit4Tat);
}