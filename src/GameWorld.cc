#include "GameWorld.h"
using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){

///
///Cube spawning with Array
///Using a 2D array to spawn multiple voxels, to spell a word
///

int X,Y;
int Z = 1;
int planeX = 12;
int planeY = 12;

int plane[planeX][planeY] = {

{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
{1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0},
{1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0},
{1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
{1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

///
///Pyramid Spawning
///using asset_manager to add the instance of a pyramid.
///

asset_manager->AddAsset(std::make_shared<PyramidAsset>(-3.0f, -2.0f, 1.0f));
asset_manager->AddAsset(std::make_shared<PyramidAsset>(-3.0f, 2.0f, 1.0f));
asset_manager->AddAsset(std::make_shared<PyramidAsset>(3.0f, 2.0f, -2.0f));
asset_manager->AddAsset(std::make_shared<PyramidAsset>(0.0f, 2.0f, -6.0f));

///
///Spawning in Ground
///Ground is spawned with;
///X offset equal to the half of the x plane so the positions are roughly center
///Y is a constant as the ground is one flat plane
///Z is determined by the Y value
///

 for( X=0; X<planeX; X++){
   for (Y=0; Y<planeY; Y++){
    if( plane[Y][X] == 1){  
      asset_manager->AddAsset(std::make_shared<CubeAsset>(X-(planeX/2), -5.0f, (Z*Y)-10));
      //spawning a cube
    }    
   }
 }

}

void GameWorld::Draw() {
  asset_manager->Draw();
}
