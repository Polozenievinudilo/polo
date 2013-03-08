/* 
 * File:   vector.h
 * Author: Filip Sergot
 *
 * Created on March 5, 2013, 3:58 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

typedef struct vector {
    float x, y;
} vector;

vector vec_times(vector, float);
vector new_vector();

float dist(vector *, vector *);

#endif	/* VECTOR_H */

