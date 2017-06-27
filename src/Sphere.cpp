#include "Sphere.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

Sphere::Sphere(double radius, Color color)
{
    this->_radius = radius;
    this->_color = color;
}


void Sphere::update(double delta_t)
{
    this->_animation.update(delta_t);
}

void Sphere::render()
{
    Form::render();
    GLUquadric *quad;
    quad = gluNewQuadric();

    gluSphere(quad, _radius, 1000, 1000);

    gluDeleteQuadric(quad);
}

bool Sphere::collusion(Basketball * basketball)
{
    return false;
}
