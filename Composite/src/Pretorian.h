#include "CombatUnit.h"

class PretorianGuard:public CombatUnit{
    std::string name="Pretorian guard";
    unsigned quantity = 60;
    public:
    PretorianGuard(std::string name, unsigned quantity):name(name), quantity(quantity){};
    std::string Name() const{
        return name;
    }
    unsigned Quantity() const{
        return quantity;
    }
};