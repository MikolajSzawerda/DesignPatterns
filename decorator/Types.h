//
// Created by mszawerd on 22.04.23.
//
#include <string>
#include <utility>
#include <fstream>
#ifndef DECORATOR_TYPES_H
#define DECORATOR_TYPES_H
class DataSource {
public:
    virtual void writeData(std::string data)=0;
    virtual std::string readData()=0;
    virtual ~DataSource()=default;
};

class FileDataSource: public DataSource{
    std::string filename;
public:
    FileDataSource(std::string filename): filename(std::move(filename)){}
    void writeData(std::string data) override {
        std::ofstream file(filename);
        if(file.is_open()){
            file<<data;
        }
        file.close();
    }

    std::string readData() override{
        std::ifstream file(filename);
        std::string buffer;
        if(file.is_open()){
            std::getline(file, buffer);
            return buffer;
        }
        return "";
    }
};

class DataSourceDecorator: public DataSource{
protected:
    DataSource& wrappee;
public:
    explicit DataSourceDecorator(DataSource& dataSource):wrappee(dataSource){}
    void writeData(std::string data) override{
        wrappee.writeData(data);
    }

    std::string readData() override{
        return wrappee.readData();
    }
};

class EncryptionDecorator: public DataSourceDecorator{
    std::string encrypt(std::string data){
        std::string tmp(key);
        while(tmp.size()<data.size()){
            tmp+=key;
        }
        for(int i=0;i<data.size();i++){
            data[i] ^= tmp[i];
        }
        return data;
    }
    std::string key;
public:
    EncryptionDecorator(DataSource& dataSource, std::string key): DataSourceDecorator(dataSource), key(std::move(key)){}

    void writeData(std::string data) override{
        DataSourceDecorator::writeData(encrypt(data));
    }

    std::string readData() override{
        return encrypt(DataSourceDecorator::readData());
    }
};
#endif //DECORATOR_TYPES_H
