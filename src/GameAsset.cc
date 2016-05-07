#include "GameAsset.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// *CHANGE ME* Send Data To Bounding Box
/// This Method Sends all the Data from spawning the Asset and sends it to the Bounding Box
/// Class to create the Bounding Box and Manipulate the Asset
////////////////////////////////////////////////////////////////////////////////////////// 

GameAsset::GameAsset(glm::vec3 Spawn, glm::vec3 xyzPos, glm::vec3 xyzTranslation, bool xyzTbool) {

Bounding_Box = std::make_shared<BoundingBox>(Spawn, xyzPos, xyzTranslation, xyzTbool); // Rename Bounding_Box

}

//////////////////////////////////////////////////////////////////////////////////////////
///*CHANGE ME* Get Model
///This class Gets the Model from the Bounding Box class, This method is normally called
///by the Draw method in GameAssetManager
////////////////////////////////////////////////////////////////////////////////////////// 


glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();  //renameGetModel
}

