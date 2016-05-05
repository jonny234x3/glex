#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

#include "BoundingBox.h"

using namespace std;

class GameAsset {
        public:

        GameAsset(glm::vec3 Spawn, glm::vec3 xyzPos/*GLfloat positionX, GLfloat positionY, GLfloat positionZ*/);
        glm::mat4 GetModel();

        virtual void Draw(GLuint) = 0;
        
        private:
        std::shared_ptr<BoundingBox> Bounding_Box;
};

#endif // 
