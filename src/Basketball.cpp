#include "Basketball.h"
#include <GL/GLU.h>
#include <stdlib.h>

#include "define.h"

using namespace std;

Basketball::Basketball(Point pos, double radius, Color color):Sphere(radius, color)
{
    Form::getAnim().setPos(pos);
    this->_throwed = false;
}

Basketball::~Basketball()
{
}

void Basketball::render()
{
    Sphere::render();
    /*GLUquadric *quad;

    quad = gluNewQuadric();

    Form::render();
    gluQuadricTexture(quad, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, Load(_file));
    gluSphere(quad, getRadius(), 1000, 1000);

    gluDeleteQuadric(quad);*/
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
    this->_animation.setSpeed(force);
}
