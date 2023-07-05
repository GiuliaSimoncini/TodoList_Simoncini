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
    void setName(const std::string &name);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    float getPrice() const;
    void setPrice(float price);
    float getDuration() const;
    void setDuration(float duration);
    float getDate() const;
    void setDate(float date);
    float getTime() const;
    void setTime(float time);
    void print() const;
    bool operator==(const Event &rhs) const;
    void operator=(const Event &rhs);
};

#endif //TODOLIST_EVENT_H
