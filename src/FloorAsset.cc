#include "FloorAsset.h"

FloorAsset::FloorAsset(GLfloat x, GLfloat y, GLfloat z) {

//////////////////////////////////////////////////////////////////////////////////
///Cube Creation
///This uses the same definitions as CubeAsset with different coordinates.
///models coordinates, origin dependant on xyz variables.
///vertex buffer models coordinates, for the triangles. 
///colour buffer models the colour of the object triangles.
///element buffer creates the cube using 12 triangles.
//////////////////////////////////////////////////////////////////////////////////

  GLfloat vertex_buffer [] {
      -0.5f + x, -0.5f + y, -0.5f + z   //0
    , -0.5f + x,  0.5f + y, -0.5f + z   //1
    ,  0.5f + x, -0.5f + y, -0.5f + z   //2
    ,  0.5f + x,  0.5f + y, -0.5f + z   //3
    , -0.5f + x, -0.5f + y,  0.5f + z   //5
    , -0.5f + x,  0.5f + y,  0.5f + z   //4
    ,  0.5f + x, -0.5f + y,  0.5f + z   //6
    ,  0.5f + x,  0.5f + y,  0.5f + z   //7
  };
  vertex_buffer_length = sizeof(vertex_buffer);

  GLfloat color_buffer [] {
      0.000f, 1.000f, 0.000f //0
    , 0.000f, 1.000f, 0.000f //1
    , 0.000f, 1.000f, 0.000f //2
    , 0.000f, 1.000f, 0.000f //3
    , 0.000f, 1.000f, 0.000f //4
    , 0.000f, 1.000f, 0.000f //5
    , 0.000f, 1.000f, 0.000f //6
    , 0.000f, 1.000f, 0.000f //7
  };
  color_buffer_length = sizeof(color_buffer);

  GLuint element_buffer []  {
      0, 1, 2  // front
    , 1, 3, 2  
    , 4, 5, 6  // back
    , 5, 7, 6  
    , 1, 5, 3  // top
    , 5, 7, 3 
    , 0, 1, 4  // left
    , 1, 5, 4  
    , 2, 3, 6  // right
    , 3, 7, 6  
    , 0, 4, 2  // bottom
    , 4, 2, 6     
  };
  element_buffer_length = sizeof(element_buffer);

  //////////////////////////////////////////////////////////////////////////////////
  ///Buffer Implementation 
  ///Transfer buffers to the GPU
  //////////////////////////////////////////////////////////////////////////////////

  // create vertex buffer
  glGenBuffers(1, &vertex_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

  // create color buffer
  glGenBuffers(1, &color_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, color_buffer_length, color_buffer, GL_STATIC_DRAW);
  
  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

FloorAsset::~FloorAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
#define checkGLError()
#endif

void FloorAsset::checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void FloorAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Floor with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

  //////////////////////////////////////////////////////////////////////////////////
  ///Buffer Arrays 
  ///use the previously transferred buffer as the vertex array.  This way
  ///we transfer the buffer once -- at construction -- not on every frame.
  //////////////////////////////////////////////////////////////////////////////////
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(1);

  checkGLError();

  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glVertexAttribPointer(
                        1,                             /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );

  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}
