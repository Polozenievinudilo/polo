/* 
 * File:   point.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 3:58 PM
 */

#ifndef POINT_H
#define	POINT_H

typedef struct point { // point (x, y)
    float x, y;
} point;

point *p_times(point *, float); // point multiplied by a float number | params: point, float multiplier | returns: point after multiplication
point *new_point(); // creates new point | returns: new point

float dist(point *, point *); // counts distance from point a, to point b || params: point a, point b || returns: float distance


#endif	/* POINT_H */

