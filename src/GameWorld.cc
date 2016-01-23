#include "GameWorld.h"
using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){
///
///Cube spawning
///using asset_manager to add multiple instances of the cube assest.]
///spawning multiple cubes
///
  
  asset_manager->AddAsset(std::make_shared<CubeAsset>(-1.0f,-2.0f,-3.0f));
  asset_manager->AddAsset(std::make_shared<CubeAsset>(1.0f,2.0f,3.0f));
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
