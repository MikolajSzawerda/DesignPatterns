#include <iostream>
#include "Types.h"

int main() {
    Dot d1(0, 0);
    Dot d2(3, 2);
    Dot d3(4, 1);
    Dot d4(5, 2);
    Circle c1(0, 0, 1);
    Circle c2(2, 3, 1);
    Circle c3(3, 4, 2);
    Circle c4(5, 1, 6);
    CompoundGraphic cg;
    cg.add(&d1);
    CompoundGraphic cg2;
    cg2.add(&c1);
    cg2.add(&d2);
    CompoundGraphic cg3;
    cg3.add(&c3);
    cg2.add(&cg3);
    cg.add(&cg2);
    cg.add(&d3);
    cg.add(&d4);
    cg.add(&c2);
    cg.move(2, -1);
    cg3.move(1, 0);
    cg2.move(-1, 1);
    cg.draw();
    return 0;
}
