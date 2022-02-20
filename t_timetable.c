#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "t_time.h"
#include "t_timetable.h"

t_timetable * t_timetable_init(int size) {
    t_timetable * timetable;

    timetable = (t_timetable *) malloc(sizeof(t_timetable));

    timetable->table = (t_timetable_item*) malloc(sizeof(t_timetable_item)* size);
    timetable->size = size;
    timetable->n = 0;

    return timetable;
}


void t_timetable_put(t_timetable * timetable, t_time * key, char * value) {
    int i, j;

    if (timetable->n == timetable->size) exit(-1);

    i = 0;
    while (i < timetable->n && t_time_cmp(key, timetable->table[i].key) > 0) {
        i++;
    }

    if (timetable->n > i && t_time_cmp(key, timetable->table[i].key) != 0) {
        for (j = timetable->n - 1; j >= i; --j) {
            timetable->table[j + 1].key = timetable->table[j].key;
            timetable->table[j + 1].value = timetable->table[j].value;
        }
    }

    timetable->table[i].key = key;
    timetable->table[i].value = value;

    if (timetable->n == i) timetable->n++;
}


char * t_timetable_get(t_timetable * timetable, t_time * key) {
    int start, end, middle, target;

    start = 0;
    end = timetable->n - 1;

    while(start <= end) {
        middle = (start + end) / 2;

        target = t_time_cmp(timetable->table[middle].key, key);

        if (target == 0) {
            return timetable->table[middle].value;

        } else if (target == 1) {
            end = middle - 1;

        } else {
            start = middle + 1;
        }
    }
    return NULL;
}


t_time * t_timetable_min(t_timetable * timetable) {
    return timetable->table[0].key;
}
t_time * t_timetable_max(t_timetable * timetable) {
    return timetable->table[timetable->n - 1].key;
}
t_time * t_timetable_floor(t_timetable * timetable, t_time * key) {
    int target;

    for (int i = timetable->n - 1; i >= 0; i--) {
        target = t_time_cmp(timetable->table[i].key, key);

        if (target == -1 || target == 0) {
            return timetable->table[i].key;
        }
    }
    return NULL;
}

t_time * t_timetable_ceiling(t_timetable * timetable, t_time * key) {
    int target;

    for (int i = 0; i <= timetable->n - 1; i++) {
        target = t_time_cmp(timetable->table[i].key, key);

        if (target == 1 || target == 0) {
            return timetable->table[i].key;
        }
    }
    return NULL;
}


void t_timetable_print(t_timetable * timetable) {
    t_time * time;
    int i, h, m, s;

    for (i = 0; i < timetable->n; ++i) {
        time = timetable->table[i].key;

        h = t_time_get_h(time);
        m = t_time_get_m(time);
        s = t_time_get_s(time);

        printf("[%02d] - %02d:%02d:%02d => %s\n", i, h, m, s, timetable->table[i].value);
    }
}