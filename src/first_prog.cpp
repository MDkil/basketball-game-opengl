// Using SDL, SDL OpenGL and standard IO
#include "BasketballGame.h"

using namespace std;

/***************************************************************************/
/* Constants declarations                                                  */
/***************************************************************************/
// Screen dimension constants
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 900;

/***************************************************************************/
/* MAIN Function                                                           */
/***************************************************************************/
int main(int argc, char* args[])
{
    BasketballGame * game = new BasketballGame(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->start();

    return 0;
}
