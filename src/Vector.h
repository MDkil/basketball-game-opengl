#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "Point.h"

class Vector : public Coordinates
{
    public:
        // Instantiates a Vector from its coordinates
        Vector(double xx=0, double yy=0, double zz=0): Coordinates(xx, yy, zz){}
        // Or with two points
        Vector(Point a, Point b);
        // Compute the vector norm
        double norm();
        Vector integral(double delta_t);
        // Overloaded standard operators
        void operator+=(const Vector &v);
};


// Overloaded standard operators
std::ostream& operator<<(std::ostream& os, const Coordinates& coord);
Vector operator+(const Vector &v1, const Vector &v2);
Vector operator-(const Vector &v);
Vector operator-(const Vector &v1, const Vector &v2);
Vector operator*(const double &k, const Vector &v);
// Scalar product
double operator*(const Vector &v1, const Vector &v2);
// Vector product
Vector operator^(const Vector &v1, const Vector &v2);


#endif // VECTOR_H
