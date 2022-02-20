#include <stdlib.h>
#include <stddef.h>
#include "t_time.h"


t_time * t_time_init(short int h, short int m, short int s) {
    t_time * time;

    if(h < 0 || h > 23) return NULL;
    if(m < 0 || m > 59) return NULL;
    if(s < 0 || s > 59) return NULL;

    time = (t_time *) malloc(sizeof(t_time));

    time->h = h;
    time->m = m;
    time->s = s;

    return time;
}

void t_time_free(t_time * time) {
    free(time);
}


int t_time_cmp(t_time * timeA, t_time * timeB) {
    int totalA, totalB;

    totalA = timeA->h * 3600 + timeA->m * 60 + timeA->s;
    totalB = timeB->h * 3600 + timeB->m * 60 + timeB->s;

    if(totalA > totalB) {
        return 1;
    } else if (totalA < totalB) {
        return -1;
    } else {
        return 0;
    }
}


int t_time_get_h(t_time * time) { return time->h; }
int t_time_get_m(t_time * time) { return time->m; }
int t_time_get_s(t_time * time) { return time->s; }