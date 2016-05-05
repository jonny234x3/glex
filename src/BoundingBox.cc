#include "BoundingBox.h"

//////////////////////////////////////////////////////////////////////////////////
/// DESC
///
//////////////////////////////////////////////////////////////////////////////////

BoundingBox::BoundingBox(glm::vec3 Spawn, glm::vec3 xyzPos/*GLfloat positionX, GLfloat positionY, GLfloat positionZ*/)
{
        this->Spawn = Spawn;
        this->xyzPos = xyzPos;
	//this->positionX = positionX;
	//this->positionY = positionY;
	//this->positionZ = positionZ;
}
glm::mat4 BoundingBox::GetModel() {
        
        Translate_Matrix = glm::translate(glm::mat4(), glm::vec3(this->Spawn/*this->positionX, this->positionY, this->positionZ*/));

        Model_Matrix = Translate_Matrix;
        return Model_Matrix;
}

// OLD CODE
// BoundingBox :: BoundingBox() : center(std::make_shared<glm::vec3(0.0, 0.0, 0.0))
//{
// bool BoundingBox::collides(std::shared_ptr<BoundingBox> other);
//   std::cout << glm::to_string(*(this->centre)) << std::endl;
//   return false;
//}

