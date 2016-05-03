#include "Camera.h"
#include <glm/ext.hpp>

  ///////////////////////////////////////////////////////////////////////////////
  /// based on the tutorial found here:
  /// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/
  /// results in a camera that follows an axis with keys to control direction, 
  /// regardless of looking direction.
  ///////////////////////////////////////////////////////////////////////////////

Camera::Camera(){


 	  cameraPosition = glm::vec3(-5.0f, 5.0f, -20.0f);
	  direction = glm::vec3(0,0,0);
	  right = glm::vec3(0,0,0);
	  up = glm::vec3(0,0,0);
          ascend = glm::vec3(0,0,0);

	  horizontalAngle = 0;
	  verticalAngle = 0;

          mouseDeltaX = 1;
	  mouseDeltaY = 1;

	  cameraMovementSpeed = 0.05;
}

glm::mat4 Camera::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){

 
	mouseDeltaX = -mouseX;
	mouseDeltaY = -mouseY;

	horizontalAngle += 0.01 * mouseDeltaX;
// This will restrict the mouse view from going too far up or down
if((verticalAngle + (0.01 * mouseDeltaY)) < 1 && (verticalAngle + (0.01 * mouseDeltaY)) > -1 ){
	verticalAngle += 0.01 * mouseDeltaY;
}

	direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),sin(verticalAngle),cos(verticalAngle) * cos(horizontalAngle));
	right = glm::vec3(sin(horizontalAngle - 3.14/2.0f),0,cos(horizontalAngle - 3.14/2.0f));
	up = glm::cross(right, direction);
       // perhaps implement an ascend so that camera can be controlled in height


 	if(input_Direction == UP){

		cameraPosition += glm::vec3(cos(verticalAngle) * sin(horizontalAngle), 0,cos(verticalAngle) * cos(horizontalAngle))* cameraMovementSpeed;

	}else if(input_Direction == DOWN){

		cameraPosition -= glm::vec3(cos(verticalAngle) * sin(horizontalAngle),0,cos(verticalAngle) * cos(horizontalAngle))* cameraMovementSpeed;

	}else if(input_Direction == LEFT){

		cameraPosition -= right * cameraMovementSpeed;

	}else if(input_Direction == RIGHT){

		cameraPosition += right * cameraMovementSpeed;
	}

	  return glm::lookAt(cameraPosition, cameraPosition + direction,up);
 }


