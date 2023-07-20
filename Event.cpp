//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "Event.h"
#include <iostream>

const std::string &Event::getName() const {
    return name;
}

void Event::setName(const std::string &name) {
    Event::name = name;
}

const std::string &Event::getDescription() const {
    return description;
}

void Event::setDescription(const std::string &description) {
    Event::description = description;
}

float Event::getPrice() const {
    return price;
}

void Event::setPrice(float price) {
    Event::price = price;
}

float Event::getDuration() const {
    return duration;
}

void Event::setDuration(float duration) {
    Event::duration = duration;
}

float Event::getDate() const {
    return date;
}

void Event::setDate(float date) {
    Event::date = date;
}

float Event::getTime() const {
    return time;
}

void Event::setTime(float time) {
    Event::time = time;
}

Event::Event(const std::string &name, const std::string &description, float price, float duration, float date,
             float time) : name(name), description(description), price(price), duration(duration), date(date),
                           time(time) {}

void Event::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
}

void Event::operator=(const Event &rhs) {
    name = rhs.name;
    description = rhs.description;
    price = rhs.price;
    duration = rhs.duration;
    date = rhs.date;
    time = rhs.time;
}

bool Event::operator==(const Event &rhs) const {
    return name == rhs.name &&
           description == rhs.description &&
           price == rhs.price &&
           duration == rhs.duration &&
           date == rhs.date &&
           time == rhs.time;
}

std::string Event::toString() const {
    return name + " " + description + " " + std::to_string(price) + " " + std::to_string(duration) + " " + std::to_string(date) + " " + std::to_string(time);
}
