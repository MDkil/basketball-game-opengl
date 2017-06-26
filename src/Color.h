#ifndef COLOR_H
#define COLOR_H

class Color
{
    public:
        float _r, _g, _b;
        Color(float r = 1.0f, float g = 1.0f, float b = 1.0f) {_r=r; _g=g; _b=b;}
};

// Constant Colors
const Color RED(1.0f, 0.0f, 0.0f);
const Color BLUE(0.0f, 0.0f, 1.0f);
const Color GREEN(0.0f, 1.0f, 0.0f);
const Color YELLOW(1.0f, 1.0f, 0.0f);
const Color WHITE(1.0f, 1.0f, 1.0f);

#endif // COLOR_H
