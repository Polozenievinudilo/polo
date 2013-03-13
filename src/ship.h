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
    float angle, // direction of a ship
          speed, // speed of a ship
          time; // time left to be touchable by asteroids
    int life; // lives
} ship;

ship new_ship(vector); // createes new ship | params: vector | returns: ship

void turn_left(ship *); // turns left | params: pointer to a ship
void turn_right(ship *); // turns right | params: pointer to a ship

#endif	/* SHIP_H */

