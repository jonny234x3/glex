#include "Game.h"

//////////////////////////////////////////////////////////////////////////////////
/// Main
/// Runs the Game file which handles the main loop of the game.
//////////////////////////////////////////////////////////////////////////////////

int main() {        
        shared_ptr<Game> game = make_shared<Game>();
        game->Start();
  }

