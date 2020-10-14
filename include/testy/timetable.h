//
// Created by Dashik on 05.10.2020.
//

#ifndef TIMETABLE_H
#define TIMETABLE_H
#define NUMBER_OF_STATION 5
#define NUMBER_OF_TRAIN 3
#define STATION1 "Nakhabino"
#define STATION2 "Anikeevka"
#define STATION3 "Opalikha"
#define STATION4 "Krasnogorskya"
#define STATION5 "Pavshino"

#include <stdio.h>

struct train {
    int train_number;
    unsigned short clock_time_arrival;
    unsigned short minute_time_arrival;
    unsigned short clock_time_departure;
    unsigned short minute_time_departure;
};

struct station {
    struct train* trains;
    char *station_name;
    size_t number_of_trains;
};

struct timetable {
    struct station* stations;
    size_t number_of_stations;
};

struct timetable* create_timetable();
void delete_timetable(struct timetable* timetable);

#endif //UNTITLED_TIMETABLE_H
