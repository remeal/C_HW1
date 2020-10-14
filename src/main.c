
#include "testy/timetable.h"
#include "testy/nearest_train.h"
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

int main() {
    char name[13];
    char time[6];
    int check;
    struct train* your_station;
    printf("%s\n", "Enter name of station (13 char max)");
    scanf("%12s", name);
    __fpurge(stdin);
    printf("%s\n", "Enter the time in format HH:MM when you would to go or enter 'now'");
    scanf("%5s", time);
    struct train found_train;
    your_station = nearest_train(name, time, &found_train);
    if (your_station == NULL)
        printf("%s", "По Вашему запросу данных не найдено");
    else {
        printf("%s\n", "Ближайший поезд:");
        printf("%s %d %s %d\n", "Прибытие", (*your_station).clock_time_arrival, ":",
               (*your_station).minute_time_arrival);
        printf("%s %d %s %d\n", "Отправление", (*your_station).clock_time_departure, ":",
               (*your_station).minute_time_departure);
    }
    return 0;

}
