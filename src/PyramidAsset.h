#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class PyramidAsset : public GameAsset {
 public:
  PyramidAsset(GLfloat x, GLfloat y, GLfloat z);
  ~PyramidAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, color_buffer_token, element_buffer_token;
  void checkError(std::string file, int line);
};

#endif // PYRAMIDASSET_H
