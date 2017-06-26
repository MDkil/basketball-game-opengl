#include "Point.h"
#include "Vector.h"

void Point::translate(const Vector &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}


double distance(Point p1, Point p2)
{
    Vector vect(p1, p2);

    return vect.norm();
}
