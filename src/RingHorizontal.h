#ifndef RINGHORIZONTAL_H
#define RINGHORIZONTAL_H
#include "Basketball.h"
#include "Form.h"


class RingHorizontal : public Form
{
private:
    float _R1, _R2;
    //int slices;
public:
    RingHorizontal(float R1 = 1.0, float R2 = 1.0, Point org = Point() );
    void render();
    void update(double delta_t);
    bool collusion(Basketball * basketball);
};

#endif // RINGHORIZONTAL_H

