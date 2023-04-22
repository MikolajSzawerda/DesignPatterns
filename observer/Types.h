//
// Created by mszawerd on 22.04.23.
//
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#ifndef OBSERVER_TYPES_H
#define OBSERVER_TYPES_H
class EventListeners {
public:
    virtual void update(std::string filename)=0;
};

class EventManager {
    std::unordered_map<std::string, std::vector<EventListeners*>> listeners;
public:
    void subscribe(const std::string& eventType, EventListeners* listener){
        if(listeners.count(eventType)){
            listeners[eventType].push_back(listener);
        } else {
            listeners.emplace(eventType, std::vector{listener});
        }
    }

    void unsubscribe(std::string const& eventType, EventListeners* listener){
        if(listeners.count(eventType)){
            auto& vec = listeners[eventType];
            auto it = std::find(vec.begin(), vec.end(), listener);
            vec.erase(it);
        }
    }

    void notify(std::string const& eventType, std::string const& filename){
        if(listeners.count(eventType)){
            for(auto l:listeners[eventType]){
                l->update(filename);
            }
        }
    }
};

class Editor {
public:
    EventManager events;
    void openFile(std::string const& filename){
        events.notify("open", filename);
    }

    void saveFile(std::string const& filename){
        events.notify("save", filename);
    }
};

class EmailAlertsListener: public EventListeners{
public:
    void update(std::string filename) override{
        std::cout<<"Someone save new file: "<<filename<<"\n";
    }
};

class LoggingListener: public EventListeners{
    std::string path;
public:
    LoggingListener(std::string path):path(std::move(path)){}

    void update(std::string filename) override{
        std::ofstream file(path, std::ios_base::app);
        if(file.is_open()){
            file<<"Someone opened new file: "<<filename<<"\n";
        }
        file.close();
    }
};
#endif //OBSERVER_TYPES_H
