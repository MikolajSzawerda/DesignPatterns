#pragma once
#include <vector>
#include "CombatUnit.h"

class CombatGroup: public CombatUnit{
    std::vector<CombatUnit*> units;
    public:
    virtual std::string Name() const=0;
    virtual unsigned Quantity() const=0;

    virtual void Add(CombatUnit & unit)=0;
    // virtual void Remove(CombatUnit const& unit)=0;
    CombatGroup()=default;
    CombatGroup(std::string name);
};