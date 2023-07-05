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
    std::ofstream fout("EventList.txt");
    fout<<"Name Description Price Duration Date Time"<<std::endl;
    fout.close();

}

void EventList::print() {
    for (auto it=events.begin(); it!=events.end(); it++) {
        it->print();
    }

}
