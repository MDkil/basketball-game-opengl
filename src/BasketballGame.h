#ifndef BASKETBALLGAME_H
#define BASKETBALLGAME_H

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>

#include "Form.h"
#include "Basketball.h"

// Max number of forms : static allocation
const int MAX_FORMS_NUMBER = 50;
// Animation actualization delay (in ms) => 100 updates per second
const Uint32 ANIM_DELAY = 10;

class BasketballGame
{
    public:
        BasketballGame(int screen_width, int screen_height);
        void start();

        virtual ~BasketballGame();

        Form* _forms_list[MAX_FORMS_NUMBER];

    protected:

    private:
        // Screen dimension constants

        int _screen_width;
        int _screen_heigh;

        // SDL Windows
        SDL_Window * _window;

        // OpenGL context
        SDL_GLContext _context;

        // Form List

        int _number_of_forms;

        Basketball * _basketball;
        Vector _force;

        // Starts up SDL, creates window, and initializes OpenGL
        bool initSDL();
        // Initializes matrices and clear color
        bool initGL();

        void loadForms();

        // Updating forms for animation
        void update(double delta_t);

        // Renders scene to the screen
        void render(const Point &cam_pos, const Point &vision_pos);

        // Frees media and shuts down SDL
        void close(SDL_Window** window);
};

#endif // BASKETBALLGAME_H
