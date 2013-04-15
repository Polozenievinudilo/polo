/* 
 * File:   asteroid.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 11:51 PM
 */

#ifndef ASTEROID_H
#define	ASTEROID_H

#include <stdbool.h>

#include "vector.h"

typedef struct asteroid {
    float angle, // direction of an asteroid
          speed,
          radius; // speed of an asteroid
    vector position; // "vector.h"
    int lvl;
    struct asteroid *next, // next asteroid
                    *prev; // previous asteroid
} asteroid;

asteroid *first_a; // first asteroid in list
asteroid *last_a; // last asteroid in list

asteroid* new_asteroid(int); // creates new asteroid | returns: address to an asteroid
void del_asteroid(asteroid *); // deletes an asteroid | params: address to an asteroid
void del_asteroids(asteroid *); // deletes all asteroids | params: address to an asteroid

void split_asteroid(asteroid *); // splits an asteroid to more smaller asteroids | params: pointer to an asteroid

void update_asteroids(); // update information about asteroids

bool point_in_asteroid(asteroid *, vector *); // checks if a vector (point) is inside an asteroids | params: pointer to an asteroid, pointer to vector | returns: true or false
asteroid *collision(asteroid *, vector); // checks if a vector is in collision with an asteroid | params: pointer to an asteroid, vector | returns: address of an asteroid

#endif	/* ASTEROID_H */

