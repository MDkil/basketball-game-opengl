#ifndef FORM_H
#define FORM_H

#include "Color.h"
#include "Animation.h"
#include "Form.h"

class Form
{
    protected:
        Color _color;
        Animation _animation;
    public:
        Animation& getAnim() {return this->_animation;}
        void setAnim(Animation animation) {this->_animation = animation;}
        // This method should update the anim object with the corresponding physical model
        // It has to be done in each inherited class, otherwise all forms will have the same movements !
        // Virtual method for dynamic function call
        // Pure virtual to ensure all objects have their physics implemented
        virtual void update(double delta_t) = 0;
        // Virtual method : Form is a generic type, only setting color and reference position
        virtual void render();
};

#endif // FORM_H
