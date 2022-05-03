#pragma once
#include <iostream>
#include <stdexcept>

class CombatUnit{
    std::string name="";
    unsigned quantity=1;
    public:
    virtual std::string Name() const=0;
    virtual unsigned Quantity() const=0;

    virtual void Add(CombatUnit & unit){
        throw std::invalid_argument("Cannot use add on leaf!");
    }
    // virtual void Remove(CombatUnit const& unit){
    //     throw std::invalid_argument("Cannot use add on leaf!");
    // }
    CombatUnit()=default;
    CombatUnit(std::string name);
};