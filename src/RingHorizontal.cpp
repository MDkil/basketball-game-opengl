#include "RingHorizontal.h"
#include<cmath>
#include "define.h"

using namespace std;

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

Vector RingHorizontal::normal()
{
    Point p1 = _animation.getPos();
    Point p2 = _animation.getPos();
    p2.x += _R1;
    Point p3 = _animation.getPos();
    p3.z += _R1;

    Vector v1 = Vector(p1, p2);
    Vector v2 = Vector(p1, p3);

    Vector normal = v1 ^ v2;

    return (1.f/normal.norm()) * normal;
}

bool RingHorizontal::isCollusion(Basketball * basketball)
{
    Vector v_origins = Vector(_animation.getPos(), basketball->getAnim().getPos());
    Vector vector_normal = this->normal();

    double distance_plan = abs(v_origins * vector_normal);

    Vector speed = basketball->getAnim().getSpeed();

    if(distance_plan <= basketball->getRadius())
    {
        Point projection = basketball->getAnim().getPos();
        projection.y = _animation.getPos().y;

        Vector v_projection_distance = Vector(_animation.getPos(), projection);
        double projection_distance = abs(v_projection_distance.norm());

        if(projection_distance <= _R1+basketball->getRadius())
        {
            if(projection_distance >= _R2)
            {
                return true;
            }
        }
    }

    return false;
}

bool RingHorizontal::collusion(Basketball * basketball) {

    Vector vector_normal = this->normal();

    Vector speed = basketball->getAnim().getSpeed();

    speed.x += -2 * abs(vector_normal.x) * speed.x;
    speed.y += -2 * abs(vector_normal.y) * speed.y;
    speed.z += -2 * abs(vector_normal.z) * speed.z;

    speed =  (1.f - BORDER_RESISTANCE )* speed ;

    while(this->isCollusion(basketball))
    {
        basketball->getAnim().setSpeed(speed);
        Point pos = basketball->getAnim().getPos();
        pos.translate(0.001 * speed);
        basketball->getAnim().setPos(pos);
    }


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
