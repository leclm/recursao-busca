#ifndef __T_TIMETABLE__
#define __T_TIMETABLE__

#include "t_time.h"


typedef struct {
    t_time * key;
    char * value;
} t_timetable_item;

typedef struct {
    t_timetable_item * table;
    int size, n;
} t_timetable;


t_timetable * t_timetable_init(int size);


void t_timetable_put(t_timetable * timetable, t_time * key, char * value);


char * t_timetable_get(t_timetable * timetable, t_time * key);


t_time * t_timetable_min(t_timetable * timetable);
t_time * t_timetable_max(t_timetable * timetable);
t_time * t_timetable_floor(t_timetable * timetable, t_time * key);
t_time * t_timetable_ceiling(t_timetable * timetable, t_time * key);


void t_timetable_print(t_timetable * timetable);

#endif