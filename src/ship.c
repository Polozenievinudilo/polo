#include <math.h>
#include <stdlib.h>

#include "ship.h"

ship *new_ship(point *p) {
    ship *s = calloc(1, sizeof(ship));
    s->position = new_point();
    s->position->x = p->x;
    s->position->y = p->y;
    
    s->angle = 0.0;
    s->speed = 3;
    s->life = 3;
    s->time = 3;
    
    return s;
}

void turn_left(ship *s) {
    s->angle -= TURN_SPEED;
}

void turn_right(ship *s) {
    s->angle += TURN_SPEED;
}