//
// Created by mszawerd on 23.04.23.
//
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef COMPOSITE_TYPES_H
#define COMPOSITE_TYPES_H

class Graphic {
public:
    virtual void move(int x, int y) = 0;

    virtual void draw() = 0;
    virtual ~Graphic()=default;
};

class Dot : public Graphic {
protected:
    int x, y;
public:
    Dot(int x, int y) : x(x), y(y) {}

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
        std::cout << "New coor: X=" << x << " Y=" << y << "\n";
    }

    void draw() override {
        std::cout << "POINT X=" << x << " Y=" << y << "\n";
    }
};

class Circle : public Dot {
protected:
    int radius;
public:
    Circle(int x, int y, int radius) : Dot(x, y), radius(radius) {}

    void draw() override {
        std::cout << "CIRCLE X=" << x << " Y=" << y << "RADIUS=" << radius << "\n";
    }
};

class CompoundGraphic : public Graphic {
    std::vector<Graphic *> children;
public:
    void add(Graphic *child) {
        children.push_back(child);
    }

    void remove(Graphic *child) {
        auto it = std::find(children.begin(), children.end(), child);
        children.erase(it);
    }

    void move(int dx, int dy) override {
        for (auto child: children) {
            child->move(dx, dy);
        }
    }

    void draw() override {
        for (auto child: children) {
            child->draw();
        }
    }
};


#endif //COMPOSITE_TYPES_H
