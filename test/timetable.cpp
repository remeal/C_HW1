#include "gtest/gtest.h"

extern "C" {
#include "testy/timetable.h"
}

TEST(create_timetable, ok) {
    struct timetable *timetable = nullptr;
    timetable = create_timetable();
    EXPECT_NE(timetable, nullptr);
    delete_timetable(timetable);
}
