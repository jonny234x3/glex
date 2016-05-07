#include "BoundingBox.h"

//////////////////////////////////////////////////////////////////////////////////
/// BoundingBox
/// Using glm vectors to store the xyz co-ordinates.
/// initialises the points using "this" keyword.
/// Tpoint is used for the translation point.
//////////////////////////////////////////////////////////////////////////////////

BoundingBox::BoundingBox(glm::vec3 Spawn, glm::vec3 xyzPos, glm::vec3 xyzTranslation, bool xyzTbool)
{
        this->Spawn = Spawn;
        this->xyzPos = xyzPos;
        SavexyzPos = xyzPos;
        this->xyzTranslation = xyzTranslation;
        this->xyzTbool = xyzTbool;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Get Model (CHANGE)
/// This gets the Model Matrics.
////////////////////////////////////////////////////////////////////////////////////////// 
glm::mat4 BoundingBox::GetModel() {

        if(xyzTbool == true) {
                Translate();
        }
        Translate_Matrix = glm::translate(glm::mat4(), glm::vec3(this->xyzPos));
        Model_Matrix = Translate_Matrix;
        return Model_Matrix;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Translate Method
/// Used for translation animation. Moves the asset based on the x, y and/or z axis.
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::Translate() {
	if(this->xyzPos.y < xyzTranslation.y ) {  // translates the y
                this->xyzPos = this->xyzPos + glm::vec3(0.0f,0.05f,0.0f);  // speed
	}else{
                this->xyzPos = SavexyzPos;
	}
}


