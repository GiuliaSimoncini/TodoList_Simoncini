//
// Created by Giulia Simoncini on 05/07/2023.
//

#ifndef TODOLIST_EVENTLIST_H
#define TODOLIST_EVENTLIST_H

#include <list>
#include "Event.h"

class EventList {
private:
    std::list<Event> events;
public:
    EventList();
    const std::list<Event> &getEvents() const;
    void addEvent(const Event &event);
    bool removeEvent(const Event &event);
    bool modifyEvent(const Event &oldEvent, const Event &newEvent);
    void print() const;
    static void printfromfile(); //stampa lista eventi dal file (non dalla lista)
    void readfile(); //metodo che legge il contenuto del file e lo salva nella lista
    void writeinfile(); //metodo che scrive il contenuto della lista nel file
    bool searchEvent(const Event &event); //metodo che cerca un evento nella lista e dice se è già presente oppure no
    bool searchByName(const std::string &name);
};

#endif //TODOLIST_EVENTLIST_H
