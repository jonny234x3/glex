#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include <GL/gl.h>

#include "common.h"
#include "GameAssetManager.h"
#include "GameAsset.h"
#include "CubeAsset.h"
#include "FloorAsset.h"
#include "PyramidAsset.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
///GameWorld allows us to separate the management of the game world from the
///nuts and bolts of game loop initialisation.  The GameWorld currently has
///a very simplified scene graph consisiting of a single GameAssetManager.
//////////////////////////////////////////////////////////////////////////////////
class GameWorld {
 public:

 explicit GameWorld();

//////////////////////////////////////////////////////////////////////////////////
///"Draw()" will draw the entire world.
//////////////////////////////////////////////////////////////////////////////////
  void Draw();

  void UpdateCameraPosition(Input, int mouseX, int mouseY);

 private:
  glm::vec3 Spawn = glm::vec3(0.0f,0.0f,0.0f);
  std::shared_ptr<GameAssetManager> asset_manager;
};
#endif // GAMEWORLD_H
