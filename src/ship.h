/* 
 * File:   ship.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 3:55 PM
 */

#ifndef SHIP_H
#define	SHIP_H

#include "vector.h"
#include "asteroid.h"

#define TURN_SPEED 0.1

typedef struct ship {
    vector position;
    float angle, speed, time;
    int life;
} ship;

ship new_ship(vector);

void turn_left(ship *);
void turn_right(ship *);

#endif	/* SHIP_H */

