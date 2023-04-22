//
// Created by mszawerd on 22.04.23.
//

#ifndef VISITOR_TYPES_H
#define VISITOR_TYPES_H

#include <cstdio>

class Shape;

class Circle;

class Rectangle;

class Triangle;

class Visitor {
public:

    void visit(Circle &c) {
        printf("Visited circle\n");

    }

    void visit(Rectangle &r) {
        printf("Visited rectangle\n");
    }

    void visit(Triangle &t) {
        printf("Visited triangle\n");
    }
};

class Shape {
public:
    virtual void draw() = 0;

    virtual void accept(Visitor &v) = 0;

};

class Circle : public Shape {
public:
    void draw() override {
        printf("Drawing circle\n");
    }

    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        printf("Drawing rectangle\n");
    }


    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        printf("Drawing triangle\n");
    }

    void accept(Visitor &v) override {
        v.visit(*this);
    }
};

class Exporter {
public:
    void export_shape(Shape *shape) {
        printf("Exporting shape\n");
    }

    void export_shape(Circle *circle) {
        printf("Exporting circle\n");
    }

    void export_shape(Rectangle *rectangle) {
        printf("Exporting rectangle\n");
    }
};


#endif //VISITOR_TYPES_H
