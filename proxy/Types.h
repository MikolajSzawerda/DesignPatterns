//
// Created by mszawerd on 23.04.23.
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#ifndef PROXY_TYPES_H
#define PROXY_TYPES_H
struct Video{
    std::string title;
    std::string id;
    std::string content;
public:
    Video(std::string title, std::string id, std::string content)
        :title(std::move(title)), id(std::move(id)), content(std::move(content)){}
};
class ThirdPartyYoutubeLib{
public:
    virtual void listVideos()=0;
    virtual std::string getVideoInfo(std::string id)=0;
    virtual std::string downloadVideo(std::string id)=0;
};

class ThirdPartyYoutubeClass: public ThirdPartyYoutubeLib {
    std::vector<Video> videos;
public:
    ThirdPartyYoutubeClass(std::vector<Video>& videos):videos(videos){}
    void listVideos() override{
        for(auto const& v:videos){
            std::cout<<v.id<<" "<<v.title<<" "<<v.content<<"\n";
        }
    }
    std::string getVideoInfo(std::string id) override{
        std::cout<<"Making long video info extraction"<<"\n";
        for(auto const& v:videos){
            if(v.id==id) return v.title;
        }
        return "";
    }

    std::string downloadVideo(std::string id) override{
        std::cout<<"Making long video download"<<"\n";
        for(auto const& v:videos){
            if(v.id==id) return v.content;
        }
        return "";
    }
};

class CachedYoutubeClass: public ThirdPartyYoutubeLib{
    ThirdPartyYoutubeLib* service;
    std::unordered_map<std::string, std::string> cache;

public:
    CachedYoutubeClass(ThirdPartyYoutubeLib* service): service(service){}
    void listVideos() override{
        service->listVideos();
    }

    std::string getVideoInfo(std::string id) override{
        return service->getVideoInfo(id);
    }

    std::string downloadVideo(std::string id) override{
        if(!cache.count(id))
            cache[id]=service->downloadVideo(id);
        return cache[id];
    }
};
#endif //PROXY_TYPES_H
