#include "Basketball.h"
#include <GL/GLU.h>
#include <stdlib.h>

using namespace std;

Basketball::Basketball(Point pos, double radius, Color color):Sphere(radius, color)
{
    Form::getAnim().setPos(pos);
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
    Sphere::update(delta_t);
    /*GLUquadric *quad;

    quad = gluNewQuadric();

    Form::render();
    gluQuadricTexture(quad, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, Load(_file));
    gluSphere(quad, getRadius(), 1000, 1000);

    gluDeleteQuadric(quad);*/
}

void Basketball::throw_action(Vector force)
{
    // TODO
}
