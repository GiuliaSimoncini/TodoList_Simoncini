//
// Created by Giulia Simoncini
//

#include "gtest/gtest.h"
#include "../EventList.h"

TEST (EventList, DefaultConstructor) {
    EventList eL;
    std::list<Event> events = eL.getEvents();
    for(const auto& event : events ){
        ASSERT_EQ(event.toString(), " ");
    }
}

TEST(EventList, TestAddEvent) {
    EventList eL;
    Event event("Cinema", "Vedere_un_film", 12, 3, 2023, 11);
    eL.addEvent(event);
    std::list<Event> events = eL.getEvents();
    for(const auto& event : events ){
        ASSERT_EQ(event.toString(), "Cinema Vedere_un_film 12.000000 3.000000 2023.000000 11.000000");
    }
}

TEST(EventList, TestRemoveEvent){
    EventList eL;
    Event event("Cinema", "Vedere_un_film", 12, 3, 2023, 11);
    eL.addEvent(event);
    eL.removeEvent(event);
    std::list<Event> events = eL.getEvents();
    for(const auto& event : events ){
        ASSERT_EQ(event.toString(), " ");
    }
}

TEST(EventList, TestModifyEvent){
    EventList eL;
    Event oldEvent("Cinema", "Vedere_un_film", 12, 3, 2023, 11);
    Event newEvent("Coop", "Spesa", 13, 5, 2022, 10);
    eL.addEvent(oldEvent);
    eL.modifyEvent(oldEvent, newEvent);
    std::list<Event> events = eL.getEvents();
    for(const auto& event : events ){
        ASSERT_EQ(event.toString(), "Coop Spesa 13.000000 5.000000 2022.000000 10.000000");
    }
}