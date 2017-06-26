#include "Animation.h"


Animation::Animation(double ph, double th, Vector accel, Vector speed, Point position)
{
    // Constructor
    // Initialization
    this->_phi = ph;
    this->_theta = th;
    this->_acceleration = accel;
    this->_speed = speed;
    this->_position = position;
}
