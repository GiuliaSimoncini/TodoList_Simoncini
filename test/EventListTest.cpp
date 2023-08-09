//
// Created by Giulia Simoncini
//

#include "gtest/gtest.h"
#include "../EventList.h"

TEST (EventList, DefaultConstructor) {
    EventList eL;
    ASSERT_EQ(eL.numberOfEvents(), 0);
}

TEST(EventList, TestAddEvent) {
    EventList eL;
    Event event("Cinema", "Vedere_un_film", 12.99, 120, 2023, 9, 5, 20, 30);
    bool flagF = eL.addEvent(event);
    ASSERT_EQ(flagF, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchEvent(event), true);

    bool flagT= eL.addEvent(event);
    ASSERT_EQ(flagT, true);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchEvent(event), true);
}

TEST(EventList, TestRemoveEvent) {
    EventList eL;
    Event event("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    bool flagA = eL.addEvent(event);
    ASSERT_EQ(flagA, false);
    bool flagR = eL.removeEvent(event);
    ASSERT_EQ(flagR, true);
    ASSERT_EQ(eL.numberOfEvents(), 0);
    ASSERT_EQ(eL.searchEvent(event), false);

    bool flagF = eL.removeEvent(event);
    ASSERT_EQ(flagF, false);
    ASSERT_EQ(eL.numberOfEvents(), 0);
    ASSERT_EQ(eL.searchEvent(event), false);
}

TEST(EventList, TestModifyEvent) {
    EventList eL;
    Event oldEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event newEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(oldEvent);
    ASSERT_EQ(flagA, false);
    bool flagM = eL.modifyEvent(oldEvent, newEvent);
    ASSERT_EQ(flagM, true);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchEvent(oldEvent), false);
    ASSERT_EQ(eL.searchEvent(newEvent), true);
}

TEST(EventList, TestSearchEvent) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchEvent(notPresentEvent), false);
    ASSERT_EQ(eL.searchEvent(addedEvent), true);
}

TEST(EventList, TestSearchByName) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchByName("Spesa"), true);
    ASSERT_EQ(eL.searchByName("Palestra"), false);
}

TEST(EventList, TestSearchByDescription) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchByDescription("Conad"), true);
    ASSERT_EQ(eL.searchByDescription("Evolution"), false);
}

TEST(EventList, TestSearchByDate) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchByDate(2023, 8, 6), true);
    ASSERT_EQ(eL.searchByDate(2023, 8, 10), false);
}

TEST(EventList, TestSearchByTime) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchByTime(10, 20), true);
    ASSERT_EQ(eL.searchByTime(9,20), false);
}

TEST(EventList, TestSearchByDateAndTime) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 10, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.searchByDateAndTime(2023,8,6,10,20), true);
    ASSERT_EQ(eL.searchByDateAndTime(2023, 8, 10, 9, 20), false);
}

TEST(EventList, TestClear) {
    EventList eL;
    Event event("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    bool flagA = eL.addEvent(event);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    eL.clear();
    ASSERT_EQ(eL.numberOfEvents(), 0);
}

TEST(EventList, TestNumberOfEventsPerDate) { //due eventi con stessa data ma uno è presente nella lista e l'altro no
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 6, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    ASSERT_EQ(eL.numberOfEventsPerDate(2023, 8, 6), 1); //data presente
    ASSERT_EQ(eL.numberOfEventsPerDate(2023, 8, 10), 0); //data non presente
}

TEST(EventList, TestPricePerDate) {
    EventList eL;
    Event addedEvent("Spesa", "Conad", 45.50, 120, 2023, 8, 6, 10, 20);
    Event notPresentEvent("Palestra", "Evolution", 10.50, 120, 2023, 8, 11, 9, 20);
    bool flagA = eL.addEvent(addedEvent);
    ASSERT_EQ(flagA, false);
    ASSERT_EQ(eL.numberOfEvents(), 1);
    float total, totalzero;
    ASSERT_EQ(eL.pricePerDate(2023, 8, 6, total), true); //data presente
    ASSERT_EQ(total, 45.50);
    ASSERT_EQ(eL.pricePerDate(2023, 8, 10, totalzero), false); //data non presente
    ASSERT_EQ(totalzero, 0);
}