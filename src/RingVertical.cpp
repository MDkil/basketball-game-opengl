#include "RingVertical.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
#include "define.h"


RingVertical::RingVertical(float R, float H, Point org )
{
    _R =R;
    _H = H;
    //col = cl;
    _animation.setPos(org);
    _animation.setSpeed(Vector(1,1,1));
}

void RingVertical::update(double delta_t)
{
    //updater
}

void RingVertical::render() {
    int    i, steps = 50;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    Form::render();
    glBegin(GL_TRIANGLE_STRIP);

     for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glColor3f(0., 1., 0.); glVertex3f(_R*cos(phi),  -_H/2., _R*sin(phi));
        glColor3f(0., 1., 0.); glVertex3f(_R*cos(phi),  _H/2.,_R*sin(phi));
    }
    glEnd();
}
