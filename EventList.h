//
// Created by Giulia Simoncini on 05/07/2023.
//

#ifndef TODOLIST_EVENTLIST_H
#define TODOLIST_EVENTLIST_H

#include <list>
#include "Event.h"

class EventList{
private:
    std::list <Event> events;
public:
    EventList();
    void addEvent(Event event);
    void removeEvent(Event event);
    bool modifyEvent(Event oldEvent, Event newEvent);
    void print();
    static void printfromfile(); //stampa lista eventi dal file (non dalla lista)
};

#endif //TODOLIST_EVENTLIST_H
