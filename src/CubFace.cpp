#include "CubFace.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

CubeFace::CubeFace(Vector v1, Vector v2, Point org, double l, double w, Color color)
{
    this->_vdir1 = 1.0 / v1.norm() * v1;
    this->_vdir2 = 1.0 / v2.norm() * v2;
    this->_animation.setPos(org);
    this->_length = l;
    this->_width = w;
    this->_color = color;
}


void CubeFace::update(double delta_t)
{
    // Do nothing, no physics associated to a Cube_face
}


void CubeFace::render()
{
    Point p1 = Point();
    Point p2 = p1, p3, p4 = p1;
    p2.translate(this->_length*this->_vdir1);
    p3 = p2;
    p3.translate(this->_width*this->_vdir2);
    p4.translate(this->_width*this->_vdir2);

    Form::render();
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex3d(p1.x, p1.y, p1.z);
        glColor3f(0,1,1);
        glVertex3d(p2.x, p2.y, p2.z);
        glColor3f(1,0,1);
        glVertex3d(p3.x, p3.y, p3.z);
        glColor3f(0,1,0);
        glVertex3d(p4.x, p4.y, p4.z);
    }
    glEnd();
}
