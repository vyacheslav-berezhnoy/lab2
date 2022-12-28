#include "factory.h"

Factory* Factory::pInstance_ = nullptr;
Factory* Factory::Instance() {
    if (!pInstance_) { pInstance_ = new Factory; }
        return pInstance_;
}