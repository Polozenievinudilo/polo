/* 
 * File:   vector.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 3:58 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

typedef struct vector { // point (x, y)
    float x, y;
} vector;

vector vec_times(vector, float); // vector (point) multiplied by a float number | params: vector, float multiplier | returns: vector after multiplication
vector new_vector(); // creates new vector | returns: new vector

float dist(vector *, vector *); // counts distance from vector a, to vector b || params: vector a, vector b || returns: float distance

#endif	/* VECTOR_H */

