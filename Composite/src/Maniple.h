#include "CombatGroup.h"

class Maniple:public CombatGroup{
    std::vector<CombatUnit*> units;
    std::string name="Maniple";
    public:
    std::string Name() const{
        return name;
    }
    unsigned Quantity() const{
        unsigned quantity=0;
        for(auto item:units){
            quantity+=item->Quantity();
        }
        return quantity;
    }

    void Add(CombatUnit & unit){
        units.push_back(&unit);
    }
    // void Remove(CombatUnit const& unit);
    Maniple(std::string name):name(name){};
};