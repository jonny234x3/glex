#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class PyramidAsset : public GameAsset {
 public:
  PyramidAsset(glm::vec3 Spawn, glm::vec3 xyzPos, glm::vec3 xyzTranslation, bool xyzTbool);
  ~PyramidAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length, color_buffer_length, vertex_buffer_length;
  GLuint vertex_buffer_token, color_buffer_token, element_buffer_token;
};

#endif // PYRAMIDASSET_H
