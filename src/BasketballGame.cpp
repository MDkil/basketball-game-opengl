#include "BasketballGame.h"

#include "CubFace.h"

#include "define.h"
#include "Basketball.h"

using namespace std;


BasketballGame::BasketballGame(int screen_width, int screen_height)
{
    this->_screen_width = screen_width;
    this->_screen_heigh = screen_height;

    if(!this->initSDL())
    {
        cout << "Failed to initialize SDL!" << endl;
        return;
    }

    if(!this->initGL())
    {
        cout << "Failed to initialize OpenGL!" << endl;
        return;
    }
    // The forms to render
    int _number_of_forms = 0;
    for (int i=0; i<MAX_FORMS_NUMBER; i++)
    {
        this->_forms_list[i] = NULL;
    }

    this->loadForms();
}

bool BasketballGame::initSDL()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        // Use OpenGL 2.1
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        // Create window
        this->_window = SDL_CreateWindow( "Basketball Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_screen_width, this->_screen_heigh, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
        if( this->_window == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            // Create context
            this->_context = SDL_GL_CreateContext(this->_window);
            if( this->_context == NULL )
            {
                cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                // Use Vsync
                if(SDL_GL_SetSwapInterval(1) < 0)
                {
                    cout << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << endl;
                }
            }
        }
    }

    return success;
}

bool BasketballGame::initGL()
{
    bool success = true;
    GLenum error = GL_NO_ERROR;

    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport : use all the window to display the rendered scene
    glViewport(0, 0, this->_screen_width, this->_screen_heigh);

    // Fix aspect ratio and depth clipping planes
    gluPerspective(40.0, (GLdouble)this->_screen_width/this->_screen_heigh, 1.0, 100);

    // Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Initialize clear color : black with no transparency
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Activate Z-Buffer
    glEnable(GL_DEPTH_TEST);

    // Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        cout << "Error initializing OpenGL!  " << gluErrorString( error ) << endl;
        success = false;
    }

    return success;
}

void BasketballGame::loadForms()
{
    // front
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(1,0,0), Vector(0,1,0), Point(0, 0, 0), WIDTH, 10.f, GREEN);
    this->_number_of_forms++;

    // Back
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(1,0,0), Vector(0,1,0), Point(0, 0, 28), WIDTH, 10.f, GREEN);
    this->_number_of_forms++;

    // right
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(0,0,1), Vector(0,1,0), Point(WIDTH, 0, 0), 28.f, 10.f, RED);
    this->_number_of_forms++;

    // right
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(0,0,1), Vector(0,1,0), Point(0, 0, 0), LENGTH, 10.f, RED);
    this->_number_of_forms++;

    // buttom
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(0,0,1), Vector(1,0,0), Point(0, 0, 0), LENGTH, WIDTH, BLUE);
    this->_number_of_forms++;

    // buttom
    this->_forms_list[this->_number_of_forms] = new CubeFace(Vector(0,0,1), Vector(1,0,0), Point(0, HEIGHT, 0), LENGTH, WIDTH, BLUE);
    this->_number_of_forms++;

    this->_basketball = new Basketball(Point(WIDTH/2.f, 2, LENGTH/2.f), 0.24, 1);
    this->_forms_list[this->_number_of_forms] = this->_basketball;
    this->_number_of_forms++;
}

void BasketballGame::start()
{
    // Main loop flag
    bool quit = false;
    Uint32 current_time, previous_time, elapsed_time;

    // Event handler
    SDL_Event event;

    // Camera position
    Point camera_position(WIDTH/2.f, 2.f, LENGTH/2.f + 4.f);
    Point vision_position(WIDTH/2.f, 2.f, 0);

    Vector force = Vector (0,5, -5);
    Point tmpPos;
    // Get first "current time"
    previous_time = SDL_GetTicks();
    // While application is running
    while(!quit)
    {
        // Handle events on queue
        while(SDL_PollEvent(&event) != 0)
        {
            int x = 0, y = 0;
            SDL_Keycode key_pressed = event.key.keysym.sym;

            switch(event.type)
            {
            // User requests quit
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                // Handle key pressed with current mouse position
                SDL_GetMouseState( &x, &y );

                switch(key_pressed)
                {
                // Quit the program when 'q' or Escape keys are pressed
                    case SDLK_ESCAPE:
                        quit = true;
                        break;

                    case SDLK_BACKSPACE:
                        this->_basketball->reset(Point(WIDTH/2.f, 2, LENGTH/2.f));
                        break;

                    case SDLK_SPACE:
                        this->_basketball->throw_action(force);
                        break;

                    case SDLK_z:
                        if((camera_position.z - MOVE_STEP) > 1)
                        {
                            camera_position.z -= MOVE_STEP;
                        }
                        break;
                    case SDLK_s:
                        if((camera_position.z + MOVE_STEP) < LENGTH)
                        {
                            camera_position.z += MOVE_STEP;
                        }
                    break;
                    case SDLK_d:
                        if((camera_position.x + MOVE_STEP) < WIDTH)
                        {
                            camera_position.x += MOVE_STEP;
                        }
                    break;
                    case SDLK_q:
                        if((camera_position.x - MOVE_STEP) > 0)
                        {
                            camera_position.x -= MOVE_STEP;
                        }
                    break;

                    case SDLK_r:
                        camera_position.y += MOVE_STEP;
                    break;
                    case SDLK_f:
                        camera_position.y -= MOVE_STEP;
                    break;

                    case SDLK_UP:
                        tmpPos = this->_basketball->getAnim().getPos();
                        tmpPos.translate(Vector(0, 0, -MOVE_STEP));
                        this->_basketball->getAnim().setPos(tmpPos);
                    break;

                    case SDLK_DOWN:
                        tmpPos = this->_basketball->getAnim().getPos();
                        tmpPos.translate(Vector(0, 0, MOVE_STEP));
                        this->_basketball->getAnim().setPos(tmpPos);
                    break;

                    case SDLK_RIGHT:
                        tmpPos = this->_basketball->getAnim().getPos();
                        tmpPos.translate(Vector(MOVE_STEP, 0, 0));
                        this->_basketball->getAnim().setPos(tmpPos);
                    break;

                    case SDLK_LEFT:
                        tmpPos = this->_basketball->getAnim().getPos();
                        tmpPos.translate(Vector(-MOVE_STEP, 0, 0));
                        this->_basketball->getAnim().setPos(tmpPos);
                    break;

                    default:
                        break;
                }
                break;
            default:
                break;
            }
        }

        // Update the scene
        current_time = SDL_GetTicks(); // get the elapsed time from SDL initialization (ms)
        elapsed_time = current_time - previous_time;
        if (elapsed_time > ANIM_DELAY)
        {
            previous_time = current_time;
            this->update(1e-3 * elapsed_time); // International system units : seconds
            // Render the scene
            this->render(camera_position, vision_position);

            // Update window screen
            SDL_GL_SwapWindow(this->_window);
        }


    }
    // Free resources and close SDL
    this->close(&this->_window);
}


// Updating forms for animation
void BasketballGame::update(double delta_t)
{
     // Update the list of forms
    unsigned short i = 0;
    while(this->_forms_list[i] != NULL)
    {
        this->_forms_list[i]->update(delta_t);
        i++;
    }
}

// Renders scene to the screen
void BasketballGame::render(const Point &cam_pos, const Point &vision_pos)
{
    // Clear color buffer and Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // Set the camera position and parameters
    gluLookAt(cam_pos.x,cam_pos.y,cam_pos.z, vision_pos.x,vision_pos.y,vision_pos.z, 0.0,1.0,0.0);
    // Isometric view
    //glRotated(-45, 0, 1, 0);
    //glRotated(30, 1, 0, -1);

    glScaled(1.0, 1.0, 1.0);

    // X, Y and Z axis
    glPushMatrix(); // Preserve the camera viewing point for further forms

    // Render the coordinates system
    glBegin(GL_LINES);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(1, 0, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 1, 0);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 0, 1);
    }
    glEnd();
    glPopMatrix(); // Restore the camera viewing point for next object

    // Render the list of forms
    unsigned short i = 0;
    while(this->_forms_list[i] != NULL)
    {
        glPushMatrix(); // Preserve the camera viewing point for further forms
        this->_forms_list[i]->render();
        glPopMatrix(); // Restore the camera viewing point for next object
        i++;
    }
}

void BasketballGame::close(SDL_Window** window)
{
//Destroy window
    SDL_DestroyWindow((this->_window));

    //Quit SDL subsystems
    SDL_Quit();
}

BasketballGame::~BasketballGame()
{
    //dtor
}
