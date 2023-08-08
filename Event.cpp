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

std::chrono::year_month_day Event::getDate() const {
    return date;
}

int Event::getYear() const {
    return static_cast<int>(date.year());
}

unsigned Event::getMonth() const {
    return static_cast<unsigned>(date.month());
}

unsigned Event::getDay() const {
    return static_cast<unsigned>(date.day());
}

float Event::getTime() const {
    return time;
}

Event::Event(const std::string &name, const std::string &description, float price, float duration, int year, unsigned month, unsigned day,
             float time) : name(name), description(description), price(price), duration(duration),
                           time(time) {
    std::chrono::year_month_day dateaus{std::chrono::year{year} / std::chrono::month{month} / std::chrono::day{day}};
    while (!dateaus.ok()) {
        std::cout << "Data non valida" << std::endl;
        std::cout << "Inserire nuovamente l'anno, il mese e il giorno" << std::endl;
        std::cin >> year;
        std::cin >> month;
        std::cin >> day;
        std::chrono::year_month_day aus{std::chrono::year{year} / std::chrono::month{month} / std::chrono::day{day}};
        dateaus = aus;
    }
    date = dateaus;
}

void Event::print() const {
    std::cout << name << " " << description << " " << price << " " << duration<< " "
     << static_cast<int>(date.year()) << " " << static_cast<unsigned>(date.month()) << " " <<
     static_cast<unsigned>(date.day()) << " " << time << std::endl;
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
