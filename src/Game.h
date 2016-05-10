#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include <boost/program_options.hpp>

#include "common.h"
#include "GameWorld.h"

class Game{
	public:
        std::shared_ptr<SDL_Window> InitWorld();
        void Draw(const std::shared_ptr<SDL_Window> &window, const std::shared_ptr<GameWorld> &game_world);
        void Start();
        private:
};

#endif //GAME_H
