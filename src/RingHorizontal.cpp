#include "RingHorizontal.h"


RingHorizontal::RingHorizontal(float R1 , float R2 , Point org )
{
    _R1=R1;
    _R2 = R2;
    _animation.setPos(org);
}

void RingHorizontal::update(double delta_t)
{
    // Do nothing, no physics associated to a Cube_face
}

bool RingHorizontal::collusion(Basketball * basketball) {
    return 0;
}

void RingHorizontal::render() {
    int    i, steps = 50;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glBindTexture (GL_TEXTURE_2D,0);
    glDisable (GL_TEXTURE_2D);
    Form::render();
    glBegin(GL_TRIANGLE_STRIP);

    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glColor3f(1., 0.5, 0.); glVertex3f(_R1*cos(phi), 0, _R1*sin(phi));
        glColor3f(1., 0.5, 0.); glVertex3f(_R2*cos(phi), 0, _R2*sin(phi));
    }
    glEnd();
}
