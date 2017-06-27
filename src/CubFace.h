#ifndef CUBFACE_H
#define CUBFACE_H

#include "Form.h"
#include "Vector.h"

class CubeFace : public Form
{
private:
    Vector _vdir1, _vdir2;
    double _length, _width;
public:
    CubeFace(Vector v1, Vector v2, Point org, double l = 1, double w= 1, Color color = Color());
    void update(double delta_t);
    void render();
    bool collusion(Basketball * basketball);
};

#endif // CUBFACE_H
