//
// Created by mszawerd on 23.04.23.
//
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#ifndef PROTOTYPE_TYPES_H
#define PROTOTYPE_TYPES_H
class Prototype{
public:
    virtual std::string getColor()=0;
    virtual Prototype* clone()=0;
    virtual ~Prototype()=default;
};

class PrototypeRegister {
    struct RegisterItem{
        std::string id;
        std::string color;
        Prototype* prototype;
        RegisterItem(std::string id, std::string color, Prototype* prototype):
        id(std::move(id)), color(std::move(color)), prototype(prototype){}
    };
    std::vector<RegisterItem*> items;
public:
    void addItem(std::string id, Prototype* p){
        items.emplace_back(new RegisterItem(std::move(id), p->getColor(), p));
    }

    Prototype* getById(std::string const& id){
        for(auto const& ri: items){
            if(ri->id==id) return ri->prototype->clone();
        }
        return nullptr;
    }

    Prototype* getByColor(std::string const& color){
        for(auto const& ri: items){
            if(ri->color==color) return ri->prototype->clone();
        }
        return nullptr;
    }
};

class Button: public Prototype{
    int x;
    int y;
    std::string color;
public:
    Button(int x, int y, std::string color):x(x), y(y), color(std::move(color)){}

    Button(Button const& prototype){
        this->x = prototype.x;
        this->y = prototype.y;
        this->color = prototype.color;
    }

    std::string getColor() override{
        return color;
    }

    Prototype* clone() override{
        return new Button(*this);
    }
};
#endif //PROTOTYPE_TYPES_H
