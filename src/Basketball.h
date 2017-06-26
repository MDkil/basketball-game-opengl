#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "string.h"

#include "Vector.h"
#include "Color.h"
#include "Sphere.h"

class Basketball : public Sphere
{
    public:
        Basketball(Point pos = Point(), double radius = 1.0, Color color = Color());
        virtual ~Basketball();
        void throw_action(Vector force); // TODO: Add throwing parameters ; throw action
        void update(double delta_t);
        void render();
    private:
        const std::string FILE = "../img/Basketball.jpg";
        std::string _file;
        double _mass;
};

#endif // BASKETBALL_H
