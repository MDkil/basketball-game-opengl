
#ifndef RINGVERTICAL_H
#define RINGVERTICAL_H
#include "Basketball.h"
#include "Form.h"


class RingVertical : public Form
{
private:
    float _R, _H;
    //int slices;
public:
    RingVertical(float R = 1.0, float H =1.0, Point org = Point() );
    void render();
    void update(double delta_t);
    bool collusion(Basketball * basketball);
};

#endif // RINGVERTICAL_H

