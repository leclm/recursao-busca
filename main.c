#include <stdio.h>
#include <stdlib.h>

#include "t_time.c"
#include "t_timetable.c"

int main(){
    t_time *time;
    t_timetable * timetable;

    char * string;
    size_t length;

    int h, m, s, size;


    scanf("%d", &size);
    timetable = t_timetable_init(size);

    scanf("%d:%d:%d", &h, &m, &s);
    while(h >= 0) {
        getchar();

        time = t_time_init(h, m, s);

        string = NULL;
        length = getline(&string, &length, stdin);
        string[length-1] = '\0';

        t_timetable_put(timetable, time, string);

        scanf("%d:%d:%d", &h, &m, &s);
    }

    t_timetable_print(timetable);

    scanf("%d:%d:%d", &h, &m, &s);
    while(h >= 0) {
        time = t_time_init(h, m, s);
        string = t_timetable_get(timetable, time);

        if(string) {
            printf("%02d:%02d:%02d => %s\n", h, m, s, string);
        } else {
            printf("%02d:%02d:%02d => No Occurrence\n", h, m, s);
        }
        scanf("%d:%d:%d", &h, &m, &s);
    }


    t_time * timeMin = t_timetable_min(timetable);
    printf("min: %02d:%02d:%02d\n", timeMin->h, timeMin->m, timeMin->s);


    t_time * timeMax = t_timetable_max(timetable);
    printf("max: %02d:%02d:%02d\n", timeMax->h, timeMax->m, timeMax->s);


    t_time * key = t_time_init(9, 20, 0);


    t_time * timeFloor = t_timetable_floor(timetable, key);
    if (timeFloor != NULL) {
        printf("floor: %02d:%02d:%02d\n", timeFloor->h, timeFloor->m, timeFloor->s);
    }


    t_time * timeCeiling = t_timetable_ceiling(timetable, key);
    if (timeCeiling != NULL) {
        printf("ceiling: %02d:%02d:%02d\n", timeCeiling->h, timeCeiling->m, timeCeiling->s);
    }
}