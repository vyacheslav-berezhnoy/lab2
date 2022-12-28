#pragma once
#include "prisoner.h"
#include "factory.h"
class Soft_Tit4Tat : public Prisoner {

public:

    void decision(const std::vector<int>&, const std::vector<int>&);
};
namespace {
    std::shared_ptr<Prisoner> CreateSoft_Tit4Tat() {
        std::shared_ptr<Soft_Tit4Tat> ret = std::make_shared<Soft_Tit4Tat>();
        return ret; 
    }
    const int SOFT_TIT4TAT = 4;
    const bool registered = Factory::Instance()->Register(SOFT_TIT4TAT, CreateSoft_Tit4Tat);
}