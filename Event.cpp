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

int Event::getDurationInMinutes() const {
    return durationInMinutes;
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

int Event::getHourOfBegin() const {
    return hourOfBegin;
}

int Event::getMinuteOfBegin() const {
    return minuteOfBegin;
}

Event::Event(const std::string &name, const std::string &description, float price, int durationInMinutes,
             int year, unsigned month, unsigned day, int hourOfBegin, int minuteOfBegin)
             : name(name), description(description), price(price), durationInMinutes(durationInMinutes){
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

    while (hourOfBegin < 0 || hourOfBegin > 23 || minuteOfBegin < 0 || minuteOfBegin > 59) {
        std::cout << "Orario non valido" << std::endl;
        std::cout << "Inserire nuovamente l'ora e i minuti" << std::endl;
        std::cin >> hourOfBegin;
        std::cin >> minuteOfBegin;
    }
    this->hourOfBegin = hourOfBegin;
    this->minuteOfBegin = minuteOfBegin;
}

void Event::print() const {
    std::cout << name << " " << description << " " << price << " " << durationInMinutes<< " "
     << static_cast<int>(date.year()) << " " << static_cast<unsigned>(date.month()) << " " <<
     static_cast<unsigned>(date.day()) << " " << hourOfBegin << " " << minuteOfBegin << std::endl;
}

void Event::operator=(const Event &rhs) {
    name = rhs.name;
    description = rhs.description;
    price = rhs.price;
    durationInMinutes = rhs.durationInMinutes;
    date = rhs.date;
    hourOfBegin = rhs.hourOfBegin;
    minuteOfBegin = rhs.minuteOfBegin;
}

bool Event::operator==(const Event &rhs) const {
    return name == rhs.name &&
           description == rhs.description &&
           price == rhs.price &&
           durationInMinutes == rhs.durationInMinutes &&
           date == rhs.date &&
           hourOfBegin == rhs.hourOfBegin &&
           minuteOfBegin == rhs.minuteOfBegin;
}
