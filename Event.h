//
// Created by Giulia Simoncini on 05/07/2023.
//

#ifndef TODOLIST_EVENT_H
#define TODOLIST_EVENT_H

#include <string>
#include <chrono>

class Event{
private:
    std::string name;
    std::string description; //descrizione attività una sola parola o parole separate da _
    float price;
    float duration;
    std::chrono::year_month_day date;
    float time;
public:
    Event(const std::string &name, const std::string &description, float price, float duration, int year, unsigned month, unsigned day, float time);
    const std::string &getName() const;
    const std::string &getDescription() const;
    float getPrice() const;
    float getDuration() const;
    std::chrono::year_month_day getDate() const; //non credo serva
    int getYear() const;
    unsigned getMonth() const;
    unsigned getDay() const;
    float getTime() const;
    void print() const;
    bool operator==(const Event &rhs) const;
    void operator=(const Event &rhs);
    std::string toString() const;
};

#endif //TODOLIST_EVENT_H
