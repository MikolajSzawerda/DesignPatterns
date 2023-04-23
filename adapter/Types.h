//
// Created by mszawerd on 23.04.23.
//
#include <math.h>
#ifndef ADAPTER_TYPES_H
#define ADAPTER_TYPES_H

class RoundPeg{
    int radius;
public:
    RoundPeg(int radius):radius(radius){}

    int getRadius(){return radius;}
};

class RoundHole{
    int radius;
public:
    RoundHole(int radius):radius(radius){}
    int getRadius(){return radius;}
    bool fits(RoundPeg peg){return peg.getRadius()<=radius;}
};

class SquarePeg{
    int width;
public:
    SquarePeg(int width):width(width){}
    int getWidth(){return width;}
};

class SquarePegAdapter: public RoundPeg {
    SquarePeg& peg;
    static double minCircle(int width){
        return width*sqrt(2)/2.0;
    }
public:
    SquarePegAdapter(SquarePeg& peg): RoundPeg(minCircle(peg.getWidth())),peg(peg){}
};

#endif //ADAPTER_TYPES_H
