#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include <glm/ext.hpp>
#include "common.h"

class Camera{

public:
	Camera();
	glm::mat4 UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY);

private:

	float cameraPositionX;
	float cameraPositionY;
	float cameraPositionZ;
	glm::vec3 cameraPosition;

	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;
        glm::vec3 ascend;

 	float horizontalAngle;
 	float verticalAngle;
 
	float mouseDeltaX;
	float mouseDeltaY;

	float cameraMouseSpeed;
        float cameraKeyboardSpeed;


};


#endif

