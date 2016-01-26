#ifndef FLOORASSET_H
#define FLOORASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class FloorAsset : public GameAsset {
 public:
  FloorAsset(GLfloat x, GLfloat y, GLfloat z);
  ~FloorAsset();
  virtual void Draw(GLuint);

  private:
  GLuint element_buffer_length, color_buffer_length, vertex_buffer_length;
  GLuint vertex_buffer_token, color_buffer_token, element_buffer_token;
  void checkError(std::string file, int line);
};

#endif // FloorASSET_H