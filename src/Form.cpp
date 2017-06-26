#include "Form.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

void Form::update(double delta_t)
{
    // Nothing to do here, animation update is done in child class method
}

void Form::render()
{
    // Point of view for rendering
    // Common for all Forms
    Point org = this->_animation.getPos();
    glTranslated(org.x, org.y, org.z);
    glColor3f(this->_color._r, this->_color._g, this->_color._b);
}
