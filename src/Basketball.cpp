#include "Basketball.h"
#include <GL/GLU.h>
#include <stdlib.h>
#include "BasketballGame.h"
#include "define.h"
#include "sdlglutils.h"

using namespace std;

Basketball::Basketball(Point pos, double radius, double mass, Color color, BasketballGame * context):Sphere(radius, color)
{
    Form::getAnim().setPos(pos);
    this->_throwed = false;
    this->_mass = mass;
    this->_context = context;
    _ball = loadTexture(BASKETBALL_IMAGE.c_str());
}

Basketball::~Basketball()
{
}

void Basketball::render()
{
    Form::render();

    // Lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat positions[4];
    positions[0] = WIDTH/2.f;
    positions[1] = HEIGHT - 1;
    positions[2] = LENGTH/2.f;
    positions[3] = 0.0;
    glLightfv(GL_LIGHT0, GL_POSITION, positions);

    GLUquadricObj *quad;

    quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _ball);

    gluSphere(quad, getRadius(), 1000, 1000);

    gluDeleteQuadric(quad);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void Basketball::update(double delta_t)
{
    if(this->_throwed)
    {
        Point pos = this->_animation.getPos();

        // Update acceleration
        this->_animation.setAccel(Vector(0, -GRAVITY, 0));
        Sphere::update(delta_t);

        // Check colusion
        unsigned short i = 0;
        while(this->_context->_forms_list[i] != NULL)
        {
            if(this->_context->_forms_list[i] == this)
            {
                i++;
                continue;
            }

            bool collusion = this->_context->_forms_list[i]->collusion(this);

            if(collusion)
            {
                //this->_animation.setPos(pos);
            }

            i++;
        }
    }
}

void Basketball::throw_action(Vector force)
{
    this->_throwed = true;
    double factor = 1.f/this->_mass;
    this->_animation.setSpeed(factor * force);
}

void Basketball::reset(Point pos)
{
    this->_throwed = false;
    this->_animation.setPos(pos);
}
