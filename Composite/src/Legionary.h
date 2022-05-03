#include "CombatUnit.h"

class Legionary: public CombatUnit{
    std::string name="Legionary";
    unsigned quantity = 120;
    public:
    Legionary(std::string name, unsigned quantity):name(name), quantity(quantity){};
    std::string Name() const{
        return name;
    }
    unsigned Quantity() const{
        return quantity;
    }
};