//
// Created by Dashik on 05.10.2020.
//

#include "../include/testy/timetable.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

struct train* nearest_train(const char* name, const char* time_to, struct train* result) {
    if (name == NULL || time_to == NULL)
        return NULL;
    unsigned short number_of_station = 0;
    unsigned short number_of_train = 0;
    struct timetable* timetable;
    char *end;
    struct tm *u;
    char time_now_hour[3] = "";
    char time_now_minute[3] = "";
    int hour_to_i, minute_to_i;
    const time_t timer = time(NULL);
    if (strcmp(time_to, "now") != 0){
        strncpy(time_now_hour, time_to, 2);
        strncpy(time_now_minute, &time_to[3], 2);
    }
    else{
        u = localtime(&timer);
        strftime(time_now_hour, 3, "%H", u);
        strftime(time_now_minute, 3, "%M", u);

    }
    hour_to_i = strtol(time_now_hour, &end, 10);
    minute_to_i = strtol(time_now_minute, &end, 10);
    timetable = create_timetable();
    while (number_of_station < timetable->number_of_stations){
        if (strncmp(timetable->stations[number_of_station].station_name, name, 3) == 0){
            while (number_of_train < timetable->stations[number_of_station].number_of_trains){
                unsigned short tmp = timetable->stations[number_of_station].trains[number_of_train].minute_time_arrival;
                unsigned short tmp2 = timetable->stations[number_of_station].trains[number_of_train].clock_time_arrival;
                if ((hour_to_i < tmp2) ||
                    (hour_to_i == tmp2 &&
                     minute_to_i <= tmp)) {
                    *result = timetable->stations[number_of_station].trains[number_of_train];
                    delete_timetable(timetable);
                    return result;
                }
                number_of_train++;
            }
            delete_timetable(timetable);
            return NULL;
        }
        number_of_station++;
    }
    delete_timetable(timetable);
    return NULL;
}


