//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "EventList.h"
#include <fstream>
#include <iostream>

void EventList::addEvent(Event event) {
    events.push_back(event);

    std::ofstream fout("EventList.txt", std::ios::app);
    fout<<event.getName()<<" "<<event.getDescription()<<" "<<event.getPrice()<<" "<<event.getDuration()<<" "<<event.getDate()<<" "<<event.getTime()<<std::endl;
    fout.close();
}

void EventList::removeEvent(Event event) {
    events.remove(event);

    std::ofstream fout("EventList.txt");
    fout<<"Name Description Price Duration Date Time"<<std::endl;

    for (auto it=events.begin(); it!=events.end(); it++) {
        fout<<it->getName()<<" "<<it->getDescription()<<" "<<it->getPrice()<<" "<<it->getDuration()<<" "<<it->getDate()<<" "<<it->getTime()<<std::endl;
    }
    fout.close();
}

bool EventList::modifyEvent(Event oldEvent, Event newEvent) { //tipo trova e sostituisci
    bool flag = false;
    for (auto it = events.begin(); it!= events.end(); it++) {
        if ((*it) == oldEvent) {
            (*it) = newEvent;
            flag = true;
        }
    }
    if (flag) {
        std::ofstream fout("EventList.txt");
        fout << "Name Description Price Duration Date Time" << std::endl;

        for (auto it = events.begin(); it != events.end(); it++) {
            fout << it->getName() << " " << it->getDescription() << " " << it->getPrice() << " " << it->getDuration()
                 << " " << it->getDate() << " " << it->getTime() << std::endl;
        }
        fout.close();
    }
    return flag;
}


EventList::EventList() {
    std::ofstream fout("EventList.txt", std::ios::app);
    std::ifstream fin("EventList.txt");
    std::string firstline;
    for (int i=0; i<6; i++){
        fin>>firstline; //non mi scrive la prima riga
    }
    if (firstline.empty())
        fout<<"Name Description Price Duration Date Time"<<std::endl;
    fout.close();
    fin.close();
}

void EventList::print() {
    std::cout<<"Name Description Price Duration Date Time"<<std::endl;
    for (auto it=events.begin(); it!=events.end(); it++) {
        it->print();
    }
}

void EventList::printfromfile() {
    std::ifstream fin("EventList.txt");
    std::string name, description;
    float date, time, price, duration;

    std::string firstline;
    for (int i=0; i<6; i++){
        fin>>firstline;
        std::cout<<firstline<<" ";
    }
    std::cout<<std::endl;
    while (fin>>name>>description>>price>>duration>>date>>time) {
        std::cout<<name<<" "<<description<<" "<<price<<" "<<duration<<" "<<date<<" "<<time<<std::endl;
    }
    fin.close();
}

void EventList::readfileandsave() {
    std::ifstream fin("EventList.txt");
    std::string name, description;
    float date, time, price, duration;

    std::string firstline;
    for (int i=0; i<6; i++){
        fin>>firstline;
    }
    while (fin>>name>>description>>price>>duration>>date>>time) {
        Event event(name, description, price, duration, date, time);
        events.push_back(event);
    }
    fin.close();
}

const std::list<Event> &EventList::getEvents() const {
    return events;
}
