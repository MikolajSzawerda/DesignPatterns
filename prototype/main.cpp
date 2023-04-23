#include <iostream>
#include "Types.h"

int main() {
    Button button(10, 20, "white");
    Button button1(100, 200, "red");
    PrototypeRegister prototypeRegister;
    prototypeRegister.addItem("a", &button);
    prototypeRegister.addItem("b", &button1);
    Prototype* p1 = prototypeRegister.getById("b");
    std::cout<<"Button b color: "<<p1->getColor()<<"\n";
    delete p1;
    return 0;
}
