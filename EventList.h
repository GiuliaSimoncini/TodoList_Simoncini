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
    bool addEvent(const Event &event);
    bool removeEvent(const Event &event);
    bool modifyEvent(const Event &oldEvent, const Event &newEvent);
    void print() const;
    void printFromFile() const; //stampa lista eventi dal file (non dalla lista)
    void readFile();
    void writeInFile();
    bool searchEvent(const Event &event) const; //metodo che cerca un evento nella lista e dice se è già presente oppure no
    bool searchByName(const std::string &name) const;
    bool searchByDescription(const std::string &description) const;
    bool searchByDate(int year, unsigned month, unsigned day) const;
    bool searchByTime(int hourOfBegin, int minuteOfBegin) const;
    bool searchByDateAndTime(int year, unsigned month, unsigned day, int hourOfBegin, int minuteOfBegin) const;
    void clear();
    int numberOfEventsPerDate(int year, unsigned month, unsigned day) const;
    unsigned numberOfEvents() const; //metodo che restituisce il numero totale di eventi presenti nella lista
    bool pricePerDate(int year, unsigned month, unsigned day, float &price) const; //dato un giorno quanto costa l'intera giornata
};

#endif //TODOLIST_EVENTLIST_H
