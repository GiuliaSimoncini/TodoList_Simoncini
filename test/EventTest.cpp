//
// Created by Giulia Simoncini
//
#include "gtest/gtest.h"
#include "../Event.h"

TEST(Event, Constructor) {
    Event e("Cinema", "Vedere_un_film", 12.99, 120, 2023, 9, 5, 20, 30);
    ASSERT_EQ("Cinema", e.getName());
    ASSERT_EQ("Vedere_un_film", e.getDescription());
    ASSERT_FLOAT_EQ(12.99, e.getPrice());
    ASSERT_EQ(120, e.getDurationInMinutes());
    ASSERT_EQ(2023, e.getYear());
    ASSERT_EQ(9, e.getMonth());
    ASSERT_EQ(5, e.getDay());
    ASSERT_EQ(20, e.getHourOfBegin());
    ASSERT_EQ(30, e.getMinuteOfBegin());
}
