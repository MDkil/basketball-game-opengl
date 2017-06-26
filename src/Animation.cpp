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

void Animation::update(double delta_t)
{
    this->_speed += delta_t * this->_acceleration;
    this->_position.translate(delta_t * this->_speed);
}
