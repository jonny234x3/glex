#include "GameWorld.h"
#include "common.h"

using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){

//////////////////////////////////////////////////////////////////////////////////
/// Cube spawning with Array
/// Using a 2D array to spawn multiple voxels
/// 1 - Floor piece
/// 2 - Floor piece and cube
/// 3 - Floor piece and pyramid
//////////////////////////////////////////////////////////////////////////////////

int X,Y; //point A,B
int Z = 1;
int planeX = 12;  //worldspace
int planeY = 12;

int plane[planeX][planeY] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1},
{1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 3},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

//////////////////////////////////////////////////////////////////////////////////
/// Spawning Floor
/// floor is spawned with;
/// The values in the array above act like coordinate points.
/// Y is a constant as the floor is one flat plane
/// Z is determined by the Y value
//////////////////////////////////////////////////////////////////////////////////
  /// We can use the above array as coordinate points, [1][3] would be
  /// coordinates x1 y3. In this way we can generate a 3D world using
  /// numbers to represent objects.
  ///////////////////////////////////////////////////////////////////

 for( X=0; X<planeX; X++){
   for (Y=0; Y<planeY; Y++){
    if( plane[Y][X] == 1){
     asset_manager->AddAsset(make_shared<FloorAsset>((X), -1.0f, (Y*Z)));
    }    

//////////////////////////////////////////////////////////////////////////////////
/// Spawning Cubes
/// Spawns floor asset and a Cube asset
//////////////////////////////////////////////////////////////////////////////////
    else if( plane[Y][X] == 2){
      asset_manager->AddAsset(make_shared<CubeAsset>((X), 2.0f, (Y*Z)));
      asset_manager->AddAsset(make_shared<FloorAsset>((X), -1.0f, (Y*Z)));
    }
//////////////////////////////////////////////////////////////////////////////////
/// Spawning Pyramids
/// Spawns floor asset and a Pyramid asset above it
//////////////////////////////////////////////////////////////////////////////////
    else if( plane[Y][X] == 3){
      asset_manager->AddAsset(make_shared<PyramidAsset>((X), 0.0f, (Y*Z)));
      asset_manager->AddAsset(make_shared<FloorAsset>((X), -1.0f, (Y*Z)));
    }
  }
 }

}

void GameWorld::Draw() {
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
  asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);
}
