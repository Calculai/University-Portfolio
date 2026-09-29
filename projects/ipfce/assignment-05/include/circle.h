#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdbool.h>
#include "point.h"

// Define a circle struct with a radius 'r' and a point 'p' for the center
typedef struct{
    point p;
    int r;
} circle;

// Function that fills an array of five circles
// Circle c_i has center (i, i) and radius i
void five_circles(circle c[5]);

// Returns true if the radius of the circle is positive
bool circle_is_valid(const circle *c);

// Translates the circle c by the vector represented by point p
void translate(circle *c, const point *p);

#endif // CIRCLE_H
