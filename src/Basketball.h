#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "string.h"

#include "Vector.h"
#include "Color.h"
#include "Sphere.h"
#include "Form.h"

class Basketball : public Sphere
{
    public:
        Basketball(Point pos = Point(), double radius = 1.0, double mass = 1, Color color = Color());
        virtual ~Basketball();
        void setForce();
        void reset(Point pos);
        void throw_action(Vector force);
        void update(double delta_t);
        void render();
        void setForms(Form * forms);

        bool _throwed;
    private:
        Form * _forms;
        const std::string FILE = "../img/Basketball.jpg";
        std::string _file;
        double _mass;

};

#endif // BASKETBALL_H
