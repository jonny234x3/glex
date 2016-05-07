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
		BoundingBox(glm::vec3 Spawn, glm::vec3 xyzPos);
                glm::mat4 GetModel();
                void Translate();

	private:
                glm::vec3 Spawn;
                glm::vec3 xyzPos;
                glm::vec3 SavexyzPos;
                //glm::vec3 xyzTranslate;
                //bool xyzT_bool;
                
                glm::mat4 Translate_Matrix;
                glm::mat4 Model_Matrix;

};

#endif //BOUNDINGBOX_H
