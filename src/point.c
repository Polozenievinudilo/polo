#include <math.h>
#include <stdlib.h>

#include "point.h"

point *p_times(point *v, float multipier) {
    point *new = calloc(1, sizeof(point));
    new->x = v->x * multipier;
    new->y = v->y * multipier;
    
    return new;
}

point *new_point() {
    point *new = calloc(1, sizeof(point));
    new->x = 0;
    new->y = 0;
    
    return new;
}

float dist(point *p1, point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}