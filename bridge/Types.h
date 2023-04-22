//
// Created by mszawerd on 22.04.23.
//
#include <math.h>
#include <stdio.h>
#ifndef BRIDGE_TYPES_H
#define BRIDGE_TYPES_H
#define MIN_CHANNEL 0
#define MAX_CHANNEL 100
#define MIN_VOLUME 0
#define MAX_VOLUME 100

class Device {
public:
    virtual bool isEnabled()=0;
    virtual void enable()=0;
    virtual void disable()=0;
    virtual int getVolume()=0;
    virtual void setVolume(int percent)=0;
    virtual int getChannel()=0;
    virtual int setChannel(int channel)=0;
};

class Radio: public Device{
    bool enabled = false;
    int currentChannel = 0;
    int currentVolume = 0;
public:
    bool isEnabled() override {
        return enabled;
    }
    void enable() override {
        enabled = true;
        printf("Making radio specifi things\n");
    }
    void disable() override {
        enabled = false;
        printf("Making radio specifi things\n");
    }
    int getVolume() override {
        printf("Making radio specifi things\n");
        return currentVolume;
    }
    void setVolume(int percent) override {
        currentVolume = std::min(std::max(percent, MIN_VOLUME), MAX_VOLUME);
        printf("Making radio specifi things\n");

    }
    int getChannel() override {
        printf("Making radio specifi things\n");
        return currentChannel;
    }
    int setChannel(int channel) override {
        currentChannel = std::min(std::max(channel, MIN_CHANNEL), MAX_CHANNEL);
        printf("Making radio specifi things\n");
    }
};

class TV: public Device{
    bool enabled = false;
    int currentChannel = 0;
    int currentVolume = 0;
public:
    bool isEnabled() override {
        return enabled;
    }
    void enable() override {
        enabled = true;
        printf("Making TV specifi things\n");
    }
    void disable() override {
        enabled = false;
        printf("Making TV specifi things\n");
    }
    int getVolume() override {
        printf("Making TV specifi things\n");
        return currentVolume;
    }
    void setVolume(int percent) override {
        currentVolume = std::min(std::max(percent, MIN_VOLUME), MAX_VOLUME);
        printf("Making TV specifi things\n");

    }
    int getChannel() override {
        printf("Making TV specifi things\n");
        return currentChannel;
    }
    int setChannel(int channel) override {
        currentChannel = std::min(std::max(channel, MIN_CHANNEL), MAX_CHANNEL);
        printf("Making TV specifi things\n");
    }
};

class Remote {
 Device& device;
public:
    Remote(Device& device): device(device){}
    void togglePower(){
        if(device.isEnabled()) device.disable();
        else device.enable();
        printf("Device state: %b\n", device.isEnabled());
    }

    void volumeDown(){
        device.setVolume(std::max(device.getVolume()-1, MIN_VOLUME));
        printf("Device volume: %d\n", device.getVolume());
    }

    void volumeUp(){
        device.setVolume(std::min(device.getVolume()+1, MAX_VOLUME));
        printf("Device volume: %d\n", device.getVolume());
    }

    void channelDown(){
        device.setChannel(std::max(device.getChannel()-1, MIN_CHANNEL));
        printf("Device channel: %d\n", device.getChannel());
    }

    void channelUp(){
        device.setChannel(std::min(device.getChannel()+1, MAX_CHANNEL));
        printf("Device channel: %d\n", device.getChannel());
    }
};

#endif //BRIDGE_TYPES_H
