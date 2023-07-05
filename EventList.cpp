//
// Created by Giulia Simoncini on 05/07/2023.
//

#include "EventList.h"
#include <fstream>
#include <iostream>

void EventList::addEvent(Event event) {
    events.push_back(event);
}

void EventList::removeEvent(Event event) {
    events.remove(event);
}

void EventList::print() {
    for (auto it=events.begin(); it!=events.end(); it++) {
        it->print();
    }
}
