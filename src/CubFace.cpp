#include "CubFace.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

#include "define.h"
#include "Basketball.h"

using namespace std;

CubeFace::CubeFace(Vector v1, Vector v2, Point org, double l, double w, Color color)
{
    this->_vdir1 = 1.0 / v1.norm() * v1;
    this->_vdir2 = 1.0 / v2.norm() * v2;
    this->_animation.setPos(org);
    this->_length = l;
    this->_width = w;
    this->_color = color;
}


bool CubeFace::collusion(Basketball * basketball)
{
    Vector vecteur_normal = this->_vdir1 ^ this->_vdir2;
    Vector v1 = Vector(this->getAnim().getPos(), basketball->getAnim().getPos());

    double distance = abs(vecteur_normal * v1);

    if(distance < basketball->getRadius())
    {
        Vector speed = basketball->getAnim().getSpeed();
        if(vecteur_normal.x != 0)
        {
            speed.x *= -1;
        }
        if(vecteur_normal.y != 0)
        {
            speed.y *= -1;
        }
        if(vecteur_normal.z != 0)
        {
            speed.z *= -1;
        }

        speed =  (1.f - BORDER_RESISTANCE )* speed ;

        basketball->getAnim().setSpeed(speed);

        return true;

    }


    return false;
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
        glColor3f(_color._r,_color._g,_color._b);
        glVertex3d(p1.x, p1.y, p1.z);
        glVertex3d(p2.x, p2.y, p2.z);
        glVertex3d(p3.x, p3.y, p3.z);
        glVertex3d(p4.x, p4.y, p4.z);
    }
    glEnd();
}
