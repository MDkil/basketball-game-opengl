#include "Form.h"

class RingVertical : public Form
{
private:
    float _R, _H;
public:
    RingVertical(float R = 1.0, float H =1.0, Point org = Point() );
    void render();
    void update(double delta_t);
};
