#include "RingVertical.h"


RingVertical::RingVertical(float R, float H, Point org )
{
    _R =R;
    _H = H;
    _animation.setPos(org);
}

void RingVertical::update(double delta_t)
{
    //updater
}

bool RingVertical::collusion(Basketball * basketball) {
    return 0;
}

void RingVertical::render() {
    int    i, steps = 50;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glBindTexture (GL_TEXTURE_2D,0);
    glDisable (GL_TEXTURE_2D);
    Form::render();
    glBegin(GL_TRIANGLE_STRIP);

     for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glColor3f(1., 0., 0.); glVertex3f(_R*cos(phi),  -_H/2., _R*sin(phi));
        glColor3f(1., 0., 0.); glVertex3f(_R*cos(phi),  _H/2.,_R*sin(phi));

    }
    glEnd();
}
