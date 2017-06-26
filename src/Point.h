#ifndef POINT_H
#define POINT_H

#include "Coordinates.h"

class Vector;

class Point : public Coordinates
{
    public:
        // Point constructor calls the base class constructor and do nothing more
        Point(double xx=0, double yy=0, double zz=0) : Coordinates(xx, yy, zz) {}
        void translate(const Vector &);
};

// Compute the distance between two points
double distance(Point p1, Point p2);

#endif // POINT_H
