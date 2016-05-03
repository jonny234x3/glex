#include "GameWorld.h"
#include "common.h"

using namespace std;
GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){

///
/// Cube spawning with Array
/// Using a 2D array to spawn multiple voxels
/// 1 - Floor piece
/// 2 - Floor piece and cube
/// 3 - Floor piece and pyramid
///

int X,Y;
int Z = -1;
int planeX = 12;
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

///
/// Spawning Floor
/// floor is spawned with;
/// X offset equal to the half of the x plane so the positions are roughly center
/// Y is a constant as the floor is one flat plane
/// Z is determined by the Y value
///

 for( X=0; X<planeX; X++){
   for (Y=0; Y<planeY; Y++){
    if( plane[Y][X] == 1){  
     asset_manager->AddAsset(make_shared<FloorAsset>((X)-(planeX/2),-6.00f,(Z*Y)));
    }    

///
/// Spawning Cubes
/// Spawns floor asset and a Cube asset
///
    else if( plane[Y][X] == 2){
      asset_manager->AddAsset(make_shared<FloorAsset>((X)-(planeX/2),-6.00f,(Z*Y)));
      asset_manager->AddAsset(make_shared<CubeAsset>((X)-(planeX/2),2.00f,(Z*Y)));

    }
///
/// Spawning Pyramids
/// Spawns floor asset and a Pyramid asset above it
///
    else if( plane[Y][X] == 3){
      asset_manager->AddAsset(make_shared<FloorAsset>((X)-(planeX/2),-6.00f,(Z*Y)));
      asset_manager->AddAsset(make_shared<PyramidAsset>((X)-(planeX/2),3.00f,(Z*Y)));
    }
  }
 }

}

void GameWorld::Draw() {
///
/// Camera Direction
///  Calculates the distance each camera movement changes the camera direction
///
     glm::vec3 direction(
        cos(Camera_Vertical) * sin(Camera_Horizontal),
        sin(Camera_Vertical),
        cos(Camera_Vertical) * cos(Camera_Horizontal)
     );

     Movement_Z = direction;

     Movement_X = glm::vec3(
        sin(Camera_Horizontal - 3.14f/2.0f),
	0,
	cos(Camera_Horizontal - 3.14f/2.0f)
     );

     glm::vec3 vup = glm::cross(Movement_X, direction);
     ///
     /// Projection matrix. : degree = 45, Field of View = 4:3 ratio, display = 0.1 unit <-> 1000 units
     ///
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 1000.0f);
     // Where the Camera Looks at
     ///
     ///  Camera view matrix.
     ///  changes where the camera position looks up to use the camera position
     ///  changes the direction you look at
     ///  Makes the world the correct orientation
     ///
     glm::mat4 Camera_View = glm::lookAt(
        Camera_Position,
        Camera_Position + direction,
        vup
     );
     glm::mat4 Camera_Model(1.0f);

     //////////////////////////////////////////////////////////////////////////////////////////
     /// Send data to Uniform Variable.
     /// Sends the data to the translate.vs shader
     //////////////////////////////////////////////////////////////////////////////////////////
     glUniformMatrix4fv(0, 1, GL_FALSE, &Camera_Projection[0][0]);
     glUniformMatrix4fv(1, 1, GL_FALSE, &Camera_View[0][0]);
     glUniformMatrix4fv(2, 1, GL_FALSE, &Camera_Model[0][0]);

     asset_manager->Draw();
}
