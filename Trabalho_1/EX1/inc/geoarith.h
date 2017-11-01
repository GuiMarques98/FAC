#ifndef GEOARITH_H
#define GEOARITH_H

#include "tipes.h"
#include <math.h>

Line determinate_mediatriz(Point q, Point p);
BOOL is_circle(Point *point);
Point find_center(Point *point);
double find_radius(Point point, Point center);
Point find_intersection(Line p, Line q);

#endif
