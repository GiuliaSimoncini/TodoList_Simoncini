//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "EventList.h"
#include <fstream>
#include <iostream>

void EventList::addEvent(const Event &event) {
    events.push_back(event);

    std::ofstream fout("EventList.txt", std::ios::app);
    fout<<event.getName()<<" "<<event.getDescription()<<" "<<event.getPrice()<<" "<<event.getDurationInMinutes()
    <<" "<<event.getYear()<<" "<<event.getMonth()<<" "<<event.getDay()<<" "<<event.getHourOfBegin()<<" "<<event.getMinuteOfBegin()<<std::endl;
    fout.close();
}

bool EventList::removeEvent(const Event &event) {
    bool flag = events.remove(event);
    if (flag)
        EventList::writeinfile();
    return flag;
}

bool EventList::modifyEvent(const Event &oldEvent, const Event &newEvent) { //tipo trova e sostituisci
    bool flag = false;
    for (auto it = events.begin(); it!= events.end(); it++) {
        if ((*it) == oldEvent) {
            (*it) = newEvent;
            flag = true;
        }
    }
    if (flag)
        EventList::writeinfile();
    return flag;
}

EventList::EventList() {
    std::ofstream fout("EventList.txt", std::ios::app);
    std::ifstream fin("EventList.txt");
    std::string firstline;
    for (int i=0; i<9; i++){
        fin>>firstline; //non scrive la prima riga
    }
    if (firstline.empty())
        fout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
    fout.close();
    fin.close();
}

void EventList::print() const {
    if (events.empty())
        std::cout << "La lista degli eventi e' vuota" << std::endl;
    else {
        std::cout << "Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin" << std::endl;
        for (auto it = events.begin(); it != events.end(); it++) {
            it->print();
        }
    }
}

void EventList::printfromfile() const {
    if (events.empty())
        std::cout << "La lista degli eventi e' vuota" << std::endl;
    else {
        std::ifstream fin("EventList.txt");
        std::string name, description;
        int year, durationInMinutes, hourOfBegin, minuteOfBegin;
        unsigned month, day;
        float price;

        std::string firstline;
        for (int i = 0; i < 9; i++) {
            fin >> firstline;
            std::cout << firstline << " ";
        }
        std::cout << std::endl;
        while (fin >> name >> description >> price >> durationInMinutes >> year >> month >> day >> hourOfBegin >> minuteOfBegin) {
            std::cout << name << " " << description << " " << price << " " << durationInMinutes << " " << year << " "
                      << month << " " << day << " " << hourOfBegin << " " << minuteOfBegin << std::endl;
        }
        fin.close();
    }
}

void EventList::readfile() {
    std::ifstream fin("EventList.txt");
    std::string name, description;
    int year, durationInMinutes, hourOfBegin, minuteOfBegin;
    unsigned month, day;
    float price;

    std::string firstline;
    for (int i=0; i<9; i++){
        fin>>firstline;
    }
    while (fin>>name>>description>>price>>durationInMinutes>>year>>month>>day>>hourOfBegin>>minuteOfBegin) {
        Event event(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
        events.push_back(event);
    }
    fin.close();
}

void EventList::writeinfile(){
    std::ofstream fout("EventList.txt");
    fout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;

    for (auto it=events.begin(); it!=events.end(); it++) {
        fout<<it->getName()<<" "<<it->getDescription()<<" "<<it->getPrice()<<" "<<it->getDurationInMinutes()
            <<" "<<it->getYear()<<" "<<it->getMonth()<<" "<<it->getDay()<<" "<<it->getHourOfBegin()<< " " << it->getMinuteOfBegin()<<std::endl;
    }
    fout.close();
}

bool EventList::searchEvent(const Event &event) const {
    bool flag = false;
    for (auto it = events.begin(); it != events.end(); it++) {
        if ((*it) == event) {
            flag = true;
        }
    }
    return flag;
}

bool EventList::searchByName(const std::string &name) const {
    bool flag = false;
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getName() == name) {
            if (!flag)
                std::cout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
            it->print();
            flag = true;
        }
    }
    return flag;
}

bool EventList::searchByDate(int year, unsigned int month, unsigned int day) const {
    bool flag = false;
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getYear() == year && it->getMonth() == month && it->getDay() == day) {
            if (!flag)
                std::cout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
            it->print();
            flag = true;
        }
    }
    return flag;
}

bool EventList::searchByTime(int hourOfBegin, int minuteOfBegin) const {
    bool flag = false;
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getHourOfBegin() == hourOfBegin && it->getMinuteOfBegin() == minuteOfBegin) {
            if (!flag)
                std::cout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
            it->print();
            flag = true;
        }
    }
    return flag;
}

bool EventList::searchByDateAndTime(int year, unsigned int month, unsigned int day, int hourOfBegin, int minuteOfBegin) const {
    bool flag = false;
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getYear() == year && it->getMonth() == month && it->getDay() == day && it->getHourOfBegin() == hourOfBegin
        && it->getMinuteOfBegin() == minuteOfBegin) {
            if (!flag)
                std::cout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
            it->print();
            flag = true;
        }
    }
    return flag;
}

void EventList::clear() {
    events.clear();
    std::ofstream fout("EventList.txt");
    fout<<"Name Description Price DurationInMinutes Year Month Day HourOfBegin MinuteOfBegin"<<std::endl;
    fout.close();
}

int EventList::numberOfEventsPerDay(int year, unsigned int month, unsigned int day) const {
    int count = 0;
    for (auto it = events.begin(); it != events.end(); it++) {
        if (it->getYear() == year && it->getMonth() == month && it->getDay() == day) {
            count++;
        }
    }
    return count;
}

const std::list<Event> &EventList::getEvents() const {
    return events;
}
