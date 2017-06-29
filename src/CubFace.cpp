#include "CubFace.h"
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

#include "define.h"
#include "Basketball.h"

using namespace std;

CubeFace::CubeFace(Vector v1, Vector v2, Point org,char* text, int divImage, double l, double w)
{
    this->_vdir1 = 1.0 / v1.norm() * v1;
    this->_vdir2 = 1.0 / v2.norm() * v2;
    this->_animation.setPos(org);
    this->_divImage = divImage;
    this->_length = l;
    this->_width = w;
    this->_texture = loadTexture(text);
}


bool CubeFace::collusion(Basketball * basketball)
{
    Vector vecteur_normal = this->_vdir1 ^ this->_vdir2;
    Vector v1 = Vector(this->getAnim().getPos(), basketball->getAnim().getPos());

    double distance = abs(vecteur_normal * v1);

    if(distance < basketball->getRadius())
    {
        Vector speed = basketball->getAnim().getSpeed();

        speed.x += -2 * abs(vecteur_normal.x) * speed.x;
        speed.y += -2 * abs(vecteur_normal.y) * speed.y;
        speed.z += -2 * abs(vecteur_normal.z) * speed.z;

        speed =  (1.f - BORDER_RESISTANCE )* speed ;

        basketball->getAnim().setSpeed(speed);

        while(abs(vecteur_normal * Vector(this->getAnim().getPos(), basketball->getAnim().getPos()) < basketball->getRadius()))
        {
            Point pos = basketball->getAnim().getPos();
            pos.translate(0.02 * speed);
            basketball->getAnim().setPos(pos);
        }

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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texture);

    Form::render();
    glBegin(GL_QUADS);
    {
        glTexCoord2d(0,0);
        glVertex3d(p1.x, p1.y, p1.z);
        glTexCoord2d(1*_divImage,0);
        glVertex3d(p2.x, p2.y, p2.z);
        glTexCoord2d(1*_divImage,1*_divImage);
        glVertex3d(p3.x, p3.y, p3.z);
        glTexCoord2d(0,1*_divImage);
        glVertex3d(p4.x, p4.y, p4.z);
    }
    glEnd();
}
