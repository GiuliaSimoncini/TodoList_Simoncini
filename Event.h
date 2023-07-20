//
// Created by Giulia Simoncini on 05/07/2023.
//

#ifndef TODOLIST_EVENT_H
#define TODOLIST_EVENT_H

#include <string>

class Event{
private:
    std::string name;
    std::string description; //descrizione attività una sola parola o parole separate da _
    float price;
    float duration;
    float date;
    float time;
public:
    Event(const std::string &name, const std::string &description, float price, float duration, float date, float time);
    const std::string &getName() const;
    const std::string &getDescription() const;
    float getPrice() const;
    float getDuration() const;
    float getDate() const;
    float getTime() const;
    void print() const;
    bool operator==(const Event &rhs) const;
    void operator=(const Event &rhs);
    std::string toString() const;
};

#endif //TODOLIST_EVENT_H
