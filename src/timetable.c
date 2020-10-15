//
// Created by Dashik on 05.10.2020.
//
#include <stdlib.h>
#include <string.h>
#include "../include/testy/timetable.h"

struct timetable* create_timetable() {
    struct timetable *timetable = NULL;
    struct station *record_to_station = NULL;
    timetable = (struct timetable*)malloc(sizeof(struct timetable));
    if (timetable == NULL)
        return NULL;

    timetable->number_of_stations = NUMBER_OF_STATION;
    timetable->stations = malloc(NUMBER_OF_STATION * sizeof(struct station));
    timetable->stations[0].station_name = STATION1;
    timetable->stations[1].station_name = STATION2;
    timetable->stations[2].station_name = STATION3;
    timetable->stations[3].station_name = STATION4;
    timetable->stations[4].station_name = STATION5;

    for (int i = 0; i < NUMBER_OF_STATION; i++){
        record_to_station = &timetable->stations[i];
        (*record_to_station).number_of_trains = NUMBER_OF_TRAIN;

        struct train *train_arr = calloc(NUMBER_OF_TRAIN, sizeof(struct train));
        if (train_arr == NULL)
            return NULL;
        (*record_to_station).trains = train_arr;
        train_arr[0].train_number            = 1;
        train_arr[0].clock_time_arrival      = i + 10;
        train_arr[0].minute_time_arrival     = 0 + rand() % 10;
        train_arr[0].clock_time_departure    = train_arr[0].clock_time_arrival;
        train_arr[0].minute_time_departure   = train_arr[0].minute_time_arrival + 1;

        for (int j = 1; j < NUMBER_OF_TRAIN; j++){
            train_arr = &(*record_to_station).trains[j];
            (*train_arr).train_number            = j + 1;
            (*train_arr).clock_time_arrival      = (*record_to_station).trains[j - 1].clock_time_arrival + 1;
            (*train_arr).minute_time_arrival     = (*record_to_station).trains[j - 1].minute_time_arrival;
            (*train_arr).clock_time_departure    = (*train_arr).clock_time_arrival;
            (*train_arr).minute_time_departure   = (*train_arr).minute_time_arrival + 1;
        }
    }
    return timetable;
}

void delete_timetable(struct timetable* timetable){
    int num = timetable->number_of_stations;
    for (int i=0; i < num; ++i) {
        free(timetable->stations[i].trains);
    }
    free(timetable->stations);
    free(timetable);
}