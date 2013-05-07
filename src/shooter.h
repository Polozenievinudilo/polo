/* 
 * File:   shooter.h
 * Author: Filip Sergot
 *
 * Created on March 6, 2013, 1:29 PM
 */

#ifndef SHOOTER_H
#define	SHOOTER_H

#include "ship.h"
#include "point.h"
#include "asteroid.h"

typedef struct shoot {
    float angle, // direction of a bullet
          time; // time to disappear
    point *position;
    int speed; // speed of a bullet
    struct shoot *next, // next bullet
                 *prev; // previous bullet
} shoot;

shoot *first_s; // first bullet
shoot *last_s; // last bullet

shoot* new_shoot(ship *); // creates new bullet | params: ship which shot this bullet | returns: pointer to a bullet
void update_shoots(); // updates information about bullets
void del_shoot(shoot *); // deletes a bullet from list | params: pointer to a bullet
asteroid *hit_shoot(shoot *, asteroid *); // checks if a bullet hit an asteroid | params: a bullet, an asteroid to start searching | returns: address to an asteroid that has just been shot

#endif	/* SHOOTER_H */

