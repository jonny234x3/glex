#include "GameWorld.h"
using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){

///
///Cube spawning with Array
///Using a 2D array to spawn multiple voxels, to spell a word
///

int X,Y;
int Z = -10;
int planeX = 12;
int planeY = 12;

int plane[planeX][planeY] = {

{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

///
///Pyramid Spawning
///using asset_manager to add the instance of a pyramid.
///

asset_manager->AddAsset(std::make_shared<PyramidAsset>(-3.0f, -2.0f, 1.0f));

///
///For loop to read positions in the array.
///using asset_manager to add the instance of a cube.
///

 for( X=0; X<planeX; X++){
   for (Y=0; Y<planeY; Y++){
    if( plane[Y][X] == 1){  
      asset_manager->AddAsset(std::make_shared<CubeAsset>(X, -Y, Z));
      //spawning a cube
    }    
   }
 }

}

void GameWorld::Draw() {
  asset_manager->Draw();
}
