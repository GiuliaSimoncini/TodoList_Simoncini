//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "EventList.h"
#include <fstream>
#include <iostream>

void EventList::addEvent(const Event &event) {
    events.push_back(event);

    std::ofstream fout("EventList.txt", std::ios::app);
    fout<<event.getName()<<" "<<event.getDescription()<<" "<<event.getPrice()<<" "<<event.getDuration()
    <<" "<<event.getYear()<<" "<<event.getMonth()<<" "<<event.getDay()<<" "<<event.getTime()<<std::endl;
    fout.close();
}

bool EventList::removeEvent(const Event &event) {
    bool flag = events.remove(event);
    if (flag) {
        std::ofstream fout("EventList.txt");
        fout<<"Name Description Price Duration Year Month Day Time"<<std::endl;

        for (auto it=events.begin(); it!=events.end(); it++) {
            fout<<it->getName()<<" "<<it->getDescription()<<" "<<it->getPrice()<<" "<<it->getDuration()
                <<" "<<it->getYear()<<" "<<it->getMonth()<<" "<<it->getDay()<<" "<<it->getTime()<<std::endl;
        }
        fout.close();
    }
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
    if (flag) {
        std::ofstream fout("EventList.txt");
        fout<<"Name Description Price Duration Year Month Day Time"<<std::endl;

        for (auto it=events.begin(); it!=events.end(); it++) {
            fout<<it->getName()<<" "<<it->getDescription()<<" "<<it->getPrice()<<" "<<it->getDuration()
                <<" "<<it->getYear()<<" "<<it->getMonth()<<" "<<it->getDay()<<" "<<it->getTime()<<std::endl;
        }
        fout.close();
    }
    return flag;
}

EventList::EventList() {
    std::ofstream fout("EventList.txt", std::ios::app);
    std::ifstream fin("EventList.txt");
    std::string firstline;
    for (int i=0; i<8; i++){
        fin>>firstline; //non scrive la prima riga
    }
    if (firstline.empty())
        fout<<"Name Description Price Duration Year Month Day Time"<<std::endl;
    fout.close();
    fin.close();
}

void EventList::print() {
    std::cout<<"Name Description Price Duration Year Month Day Time"<<std::endl;
    for (auto it=events.begin(); it!=events.end(); it++) {
        it->print();
    }
}

void EventList::printfromfile() {
    std::ifstream fin("EventList.txt");
    std::string name, description;
    int year;
    unsigned month, day;
    float time, price, duration;

    std::string firstline;
    for (int i=0; i<8; i++){
        fin>>firstline;
        std::cout<<firstline<<" ";
    }
    std::cout<<std::endl;
    while (fin>>name>>description>>price>>duration>>year>>month>>day>>time) {
        std::cout<<name<<" "<<description<<" "<<price<<" "<<duration<<" "<<year<<" "<<month<<" "
        <<day<<" "<<time<<std::endl;
    }
    fin.close();
}

void EventList::readfile() {
    std::ifstream fin("EventList.txt");
    std::string name, description;
    int year;
    unsigned month, day;
    float time, price, duration;

    std::string firstline;
    for (int i=0; i<8; i++){
        fin>>firstline;
    }
    while (fin>>name>>description>>price>>duration>>year>>month>>day>>time) {
        Event event(name, description, price, duration, year, month, day, time);
        events.push_back(event);
    }
    fin.close();
}

const std::list<Event> &EventList::getEvents() const {
    return events;
}
