//
// Created by mszawerd on 23.04.23.
//
#include <string>
#ifndef SINGLETON_TYPES_H
#define SINGLETON_TYPES_H

class Database {
    static Database *db;

    Database()=default;

public:
    Database(Database &other) = delete;
    void operator=(const Database &) = delete;
    static Database* getInstance();

    bool query(std::string const& sql){
        return !sql.empty();
    }
};
Database* Database::db= nullptr;
Database* Database::getInstance() {
    if (db == nullptr) {
        db = new Database();
    }
    return db;
}
#endif //SINGLETON_TYPES_H
