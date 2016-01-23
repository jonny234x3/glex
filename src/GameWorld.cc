#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
///
///Cube spawning
///using asset_manager to add multiple instances of the cube assest.]
///spawning multiple cubes
///
  asset_manager = std::make_shared<GameAssetManager>(mode);
  asset_manager->AddAsset(std::make_shared<CubeAsset>(-1.0f,-2.0f,-3.0f));
  asset_manager->AddAsset(std::make_shared<CubeAsset>(1.0f,2.0f,3.0f));
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
