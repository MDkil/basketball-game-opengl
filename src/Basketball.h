#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "string.h"

#include "Vector.h"
#include "Color.h"
#include "Sphere.h"
#include "Form.h"

class BasketballGame;

class Basketball : public Sphere
{
    public:
        Basketball(Point pos = Point(), double radius = 1.0, double mass = 1, Color color = Color(), BasketballGame * context = NULL);
        virtual ~Basketball();
        void setForce();
        void reset(Point pos);
        void throw_action(Vector force);
        void update(double delta_t);
        void render();
        void setForms(Form * forms[10]);

        bool _throwed;
    private:
        const std::string BASKETBALL_IMAGE = "img/Basketball.jpg";
        GLuint _ball;
        double _mass;
        BasketballGame * _context;

};

#endif // BASKETBALL_H
