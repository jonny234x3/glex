#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <memory>
#include <iostream>
#include <utility>
#include <ostream>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;


class BoundingBox{
	public:
		BoundingBox(glm::vec3 Spawn, glm::vec3 xyzPos/*GLfloat positionX, GLfloat positionY, GLfloat positionZ*/);
                glm::mat4 GetModel();

	private:
                glm::vec3 Spawn;
                glm::vec3 xyzPos;
		//GLfloat positionX;
		//GLfloat positionY;
		//GLfloat positionZ;
                
                glm::mat4 Translate_Matrix;
                glm::mat4 Model_Matrix;

};

#endif //BOUNDINGBOX_H
