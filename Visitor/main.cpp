#include <iostream>
#include "Types.h"
#include <vector>

using namespace std;

int main() {
    Circle c1;
    Rectangle r1;
    Rectangle r2;
    Triangle t1;
    Exporter e;
    vector<Shape *> shapes{&c1, &r1, &r2, &t1};
    printf("Using wrong solution\n");
    for (auto s: shapes) {
        s->draw();
        e.export_shape(s);
    }
    printf("\n\nUsing visitator pattern\n");
    Visitor v;
    for (auto s: shapes) {
        s->accept(v);
    }
    return 0;
}
