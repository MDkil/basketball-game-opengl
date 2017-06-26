#ifndef ANIMATION_H
#define ANIMATION_H

#include "Vector.h"

class Animation
{
    private:
        double _phi, _theta; // Azimuthal and polar angles for local coordinate system orientation
        Vector _acceleration, _speed; //  Instantaneous acceleration and speed
        Point _position; // Instantaneous position of the local coordinate system origin

    public:
        Animation(double ph = 0.0, double th = 0.0,
                  Vector accel = Vector(0.0, 0.0, 0.0),
                  Vector speed = Vector(0.0, 0.0, 0.0),
                  Point p = Point(0.0, 0.0, 0.0)
                  );
        const double getPhi() {return this->_phi;}
        const double getTheta() {return this->_theta;}
        void setPhi(double agl) {this->_phi = agl;}
        void setTheta(double agl) {this->_theta = agl;}
        const Vector getAcceleration() {return this->_acceleration;}
        const Vector getSpeed() {return this->_speed;}
        void setAccel(Vector vect) {this->_acceleration = vect;}
        void setSpeed(Vector vect) {this->_speed = vect;}
        const Point getPos() {return this->_position;}
        void setPos(Point pt) {this->_position = pt;}

        void update(double delta_t);
};

#endif // ANIMATION_H
