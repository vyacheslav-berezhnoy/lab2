#pragma once
#include <stdexcept>
#include <map>
#include "prisoner.h"
class Factory
{
public:
    static Factory* Instance();
    bool Register(const int& id, CreatePrisoner creator)
    {
        return associations_.insert(AssocMap::value_type(id, creator)).second;
    }
    bool Unregister(const int& id)
    {
        return associations_.erase(id) == 1;
    }
    std::shared_ptr<Prisoner> CreateObject(const int& id)
    {
        typename AssocMap::const_iterator i = associations_.find(id);
        if (i != associations_.end())
        {
            return (i->second)();
        }
        else {
            throw std::runtime_error("The class is not registered yet!");
        }
}
private:
    //typedef std::map<int, Prisoner> AssocMap;
    typedef std::map<int, CreatePrisoner> AssocMap;
    AssocMap associations_;
    Factory(const Factory&) {};
    Factory() {};
    static Factory* pInstance_;
};