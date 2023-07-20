//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "Event.h"
#include <iostream>

const std::string &Event::getName() const {
    return name;
}

const std::string &Event::getDescription() const {
    return description;
}

float Event::getPrice() const {
    return price;
}

float Event::getDuration() const {
    return duration;
}

float Event::getDate() const {
    return date;
}

float Event::getTime() const {
    return time;
}

Event::Event(const std::string &name, const std::string &description, float price, float duration, float date,
             float time) : name(name), description(description), price(price), duration(duration), date(date),
                           time(time) {}

void Event::print() const {
    std::cout << name << " " << description << " " << price << " " << duration << " " << date << " " << time
              << std::endl;
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
