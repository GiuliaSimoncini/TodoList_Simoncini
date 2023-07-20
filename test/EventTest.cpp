//
// Created by Giulia Simoncini
//
#include "gtest/gtest.h"
#include "../Event.h"

TEST(Event, Constructor) {
    Event e("Cinema", "Vedere_un_film", 12, 3, 2023, 11);
    ASSERT_EQ("Cinema", e.getName());
    ASSERT_EQ("Vedere_un_film", e.getDescription());
    ASSERT_EQ(12, e.getPrice());
    ASSERT_EQ(3, e.getDuration());
    ASSERT_EQ(2023, e.getDate());
    ASSERT_EQ(11, e.getTime());
}

