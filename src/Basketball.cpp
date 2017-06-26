#include "Basketball.h"
#include <GL/GLU.h>
#include <stdlib.h>

#include "define.h"

using namespace std;

Basketball::Basketball(Point pos, double radius, double mass, Color color):Sphere(radius, color)
{
    Form::getAnim().setPos(pos);
    this->_throwed = false;
    this->_mass = mass;
}

Basketball::~Basketball()
{
}

void Basketball::render()
{
    Sphere::render();
}

void Basketball::update(double delta_t)
{
    if(this->_throwed)
    {
        // Update acceleration
        this->_animation.setAccel(Vector(0, -GRAVITY, 0));
        Sphere::update(delta_t);
    }
}

void Basketball::throw_action(Vector force)
{
    this->_throwed = true;
    double factor = 1.f/this->_mass;
    this->_animation.setSpeed(factor * force);
}

void Basketball::reset(Point pos)
{
    this->_throwed = false;
    this->_animation.setPos(pos);
}
