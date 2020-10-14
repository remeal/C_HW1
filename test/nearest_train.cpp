#include "testy/timetable.h"
#include "gtest/gtest.h"

extern "C" {
#include "testy/nearest_train.h"
}

TEST(nearest_train, set_time) {
    struct train found_train;
    struct train *train = nearest_train("Pavshino", "15:02", &found_train);
    EXPECT_EQ(train->clock_time_arrival, 15);
    EXPECT_EQ(train->minute_time_arrival, 3);
}

TEST(nearest_train, wrong_station) {
    struct train found_train;
    struct train *train = nearest_train("Lavshino", "09:00", &found_train);
    EXPECT_EQ(train, nullptr);
}

TEST(nearest_train, no_train) {
    struct train found_train;
    struct train *train = nearest_train("Pavshino", "20:00", &found_train);
    EXPECT_EQ(train, nullptr);
}

TEST(nearest_train, nullptr_value) {
    struct train found_train;
    struct train *train = nearest_train(nullptr, nullptr, &found_train);
    EXPECT_EQ(train, nullptr);
}

TEST(nearest_train, set_local_time) {
    struct train found_train;
    struct train *train = nearest_train("Pavshino", "now", &found_train);
    struct tm *u;
    const time_t timer = time(NULL);
    u = localtime(&timer);
    if (u->tm_hour < 16)
        EXPECT_NE(train, nullptr);
    else
        EXPECT_EQ(train, nullptr);
}