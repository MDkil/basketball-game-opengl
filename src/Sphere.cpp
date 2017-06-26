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
    // Complete this part
}

void Sphere::render()
{
    GLUquadric *quad;

    quad = gluNewQuadric();

    Form::render();
    gluSphere(quad, _radius, 1000, 1000);

    gluDeleteQuadric(quad);
}
