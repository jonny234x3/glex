#include "Camera.h"
#include <glm/ext.hpp>

///////////////////////////////////////////////////////////////////////////////
/// based on the tutorial found here:
/// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/
/// results in a camera that follows an axis
/// 
///////////////////////////////////////////////////////////////////////////////

Camera::Camera(){

    cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    direction = glm::vec3(0,0,0);
    right = glm::vec3(0,0,0);
    up = glm::vec3(0,0,0);
    ascend = glm::vec3(0,0,0);

    horizontalAngle = 0;
    verticalAngle = 0;

    mouseDeltaX = 1;
    mouseDeltaY = 1;

    cameraMouseSpeed = 0.005;
    cameraKeyboardSpeed = 0.25;
    }

///////////////////////////////////////////////////////////////////////////////
/// Update Camera Position
/// Key control is INDEPENDENT of camera direction.
/// Mouse position is updated using the inverse of the x and y positions.
/// Uses the Keyboard inputs from the main.
///////////////////////////////////////////////////////////////////////////////

glm::mat4 Camera::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){

  mouseDeltaX = -mouseX;
  mouseDeltaY = -mouseY;
  horizontalAngle += cameraMouseSpeed * mouseDeltaX;

  // This will restrict the mouse view from going too far up or down

    if((verticalAngle + (cameraMouseSpeed * mouseDeltaY)) < 1 && (verticalAngle + (0.01 * mouseDeltaY)) > -1 ){
        verticalAngle += 0.01 * mouseDeltaY;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// Calculates the direction, the travel right and the travel up.
    /// These are inverted to get left and down travel.
    ///////////////////////////////////////////////////////////////////////////////

    direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
                          0,
                          cos(verticalAngle) * cos(horizontalAngle));

    right = glm::vec3(sin(horizontalAngle - 3.14/2.0f),0,cos(horizontalAngle - 3.14/2.0f));

    up = glm::cross(right, direction);

    if(input_Direction == FORWARD){
    cameraPosition += glm::vec3(cos(verticalAngle) * sin(horizontalAngle), 
                                      0,
                                      cos(verticalAngle) * cos(horizontalAngle))
                                      * cameraKeyboardSpeed;
    }else if(input_Direction == DOWN){
    cameraPosition -= glm::vec3(cos(verticalAngle) * sin(horizontalAngle),
                                    0,
                                    cos(verticalAngle) * cos(horizontalAngle))
                                    * cameraKeyboardSpeed;
    }else if(input_Direction == LEFT){
             cameraPosition -= right * cameraKeyboardSpeed;
    }else if(input_Direction == RIGHT){
             cameraPosition += right * cameraKeyboardSpeed;
    }else if(input_Direction == ASCEND){
             cameraPosition += up * cameraKeyboardSpeed;
    }else if(input_Direction == DESCEND){
             cameraPosition -= up * cameraKeyboardSpeed;
    }

    return glm::lookAt(cameraPosition, cameraPosition + direction , up);
 }
