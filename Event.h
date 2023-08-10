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
    int durationInMinutes;
    std::chrono::year_month_day date;
    int hourOfBegin;
    int minuteOfBegin;
public:
    Event(const std::string &name, const std::string &description, float price, int durationInMinutes,
          int year, unsigned month, unsigned day, int hourOfBegin, int minuteOfBegin);
    const std::string &getName() const;
    const std::string &getDescription() const;
    float getPrice() const;
    int getDurationInMinutes() const;
    int getYear() const;
    unsigned getMonth() const;
    unsigned getDay() const;
    int getHourOfBegin() const;
    int getMinuteOfBegin() const;
    void print() const;
    bool operator==(const Event &rhs) const;
    Event& operator=(const Event &rhs);
};

#endif //TODOLIST_EVENT_H
