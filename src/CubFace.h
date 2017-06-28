#ifndef CUBFACE_H
#define CUBFACE_H

#include "Form.h"
#include "Vector.h"

class CubeFace : public Form
{
private:
    Vector _vdir1, _vdir2;
    double _length, _width;
    int _divImage;
    GLuint _texture;
public:
    CubeFace(Vector v1, Vector v2, Point org, char* tex="", int divImage=1, double l = 1, double w= 1);
    void update(double delta_t);
    void render();
    bool collusion(Basketball * basketball);
};

#endif // CUBFACE_H
