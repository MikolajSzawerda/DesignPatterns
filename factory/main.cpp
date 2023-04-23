#include <iostream>
#include "Types.h"
int main() {
    GUIFactory* factory = new WinFactory();
    Application app(factory);
    app.createUI();
    app.paint();
    delete factory;
    GUIFactory* macFactory = new MacFactory();
    Application app1(macFactory);
    app.createUI();
    app.paint();
    delete macFactory;
    return 0;
}
