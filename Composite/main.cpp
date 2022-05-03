#include <iostream>
#include "src/Legionary.h"
#include "src/Maniple.h"
#include "src/Pretorian.h"

int main(int, char**) {
    Legionary l1("Vell trained legionary", 10);
    PretorianGuard p1("Ceasar Pretorian Guards", 5);
    Maniple m("I Rome Maniple");
    Maniple m2("Big Maniple");
    m.Add(l1);
    m.Add(p1);
    m2.Add(m);
    m2.Add(l1);
    m2.Add(p1);
    std::cout<<m2.Quantity()<<std::endl;
}
