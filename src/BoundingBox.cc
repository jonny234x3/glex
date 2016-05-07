#include "BoundingBox.h"

//////////////////////////////////////////////////////////////////////////////////
/// BoundingBox
/// Using glm vectors to store the xyz co-ordinates.
/// initialises the points using "this" keyword.
//////////////////////////////////////////////////////////////////////////////////

BoundingBox::BoundingBox(glm::vec3 Spawn, glm::vec3 xyzPos /* glm::vec3 xyzTranslat, bool xyzT_bool*/)
{
        this->Spawn = Spawn;
        this->xyzPos = xyzPos;
        SavexyzPos = xyzPos;
        // this->xyzTranslate = xyzTranslate;
        // this->xyzT_bool;

}

//////////////////////////////////////////////////////////////////////////////////////////
/// Get Model (CHANGE)
/// This gets the Model Matrics.
////////////////////////////////////////////////////////////////////////////////////////// 
glm::mat4 BoundingBox::GetModel() {
        Translate();
        Translate_Matrix = glm::translate(glm::mat4(), glm::vec3(this->xyzPos));
        Model_Matrix = Translate_Matrix;
        return Model_Matrix;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Translate Method
/// Used for translation animation. Moves the asset based on the x, y and/or z axis.
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::Translate() {
	if(this->xyzPos.y < 10.0f) {  // translates the y
                this->xyzPos = this->xyzPos + glm::vec3(0.0f,0.1f,0.0f);
	}else{
                this->xyzPos = SavexyzPos;
	}
}


