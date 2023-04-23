//
// Created by mszawerd on 23.04.23.
//
#include <iostream>

#ifndef FACTORY_TYPES_H
#define FACTORY_TYPES_H

class Button {
public:
    virtual void whois() = 0;

    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void whois() = 0;

    virtual ~Checkbox() = default;
};

class WinButton : public Button {
public:
    void whois() override {
        printf("I'm windows button\n");
    }
};


class MacButton : public Button {
public:
    void whois() override {
        printf("I'm mac button\n");
    }
};


class WinCheckbox : public Checkbox {
public:
    void whois() override {
        printf("I'm windows checkbox\n");
    }
};


class MacCheckbox : public Checkbox {
public:
    void whois() override {
        printf("I'm mac checkbox\n");
    }
};

class GUIFactory {
public:
    virtual Button *createButton() = 0;

    virtual Checkbox *createCheckbox() = 0;

    virtual ~GUIFactory() = default;
};

class WinFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new WinButton();
    }

    Checkbox *createCheckbox() override {
        return new WinCheckbox();
    }
};


class MacFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new MacButton();
    }

    Checkbox *createCheckbox() override {
        return new MacCheckbox();
    }
};

class Application {
    GUIFactory *factory = nullptr;
    Button *button = nullptr;
    Checkbox *checkbox = nullptr;
public:
    Application(GUIFactory *factory) : factory(factory) {}

    void createUI() {
        delete button;
        delete checkbox;

        button = factory->createButton();
        checkbox = factory->createCheckbox();
    }

    void paint() {
        if (button != nullptr && checkbox != nullptr) {
            button->whois();
            checkbox->whois();
        }
    }

    ~Application() {
        delete button;
        delete checkbox;
    }
};

#endif //FACTORY_TYPES_H
