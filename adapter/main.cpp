#include <iostream>
#include "Types.h"
int main() {
    RoundHole hole(10);
    RoundPeg peg(5);
    SquarePeg squarePeg(2);
    std::cout<<"Hole and peg: "<<hole.fits(peg)<<"\n";
    RoundPeg* adapterPeg = new SquarePegAdapter(squarePeg);
//    SquarePegAdapter pegAdapter(squarePeg);
    std::cout<<"Hole and square: "<<hole.fits(*adapterPeg)<<"\n";
    delete adapterPeg;
    return 0;
}
