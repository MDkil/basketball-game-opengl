#ifndef SPHERE_H
#define SPHERE_H

#include "Form.h"
#include "Vector.h"

class Sphere : public Form
{
private:
    // The sphere center is aligned with the coordinate system origin
    // => no center required here, information is stored in the anim object
    double _radius;
    public:
        Sphere(double radius = 1.0, Color color = Color());
        const double getRadius() {return this->_radius;}
        void setRadius(double radius) {this->_radius = radius;}
        void update(double delta_t);
        void render();
        bool collusion(Basketball * basketball);
};

#endif // SPHERE_H
