#include "GameAssetManager.h"

//////////////////////////////////////////////////////////////////////////////////
/// Creates a GameAssetManager to load the correct shaders.
//////////////////////////////////////////////////////////////////////////////////

GameAssetManager::GameAssetManager() {
  std::string vertex_shader("shaders/translate.vs");
  std::string fragment_shader("shaders/fragment.fs");

  program_token = CreateGLProgram(vertex_shader, fragment_shader);
}

void GameAssetManager::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){
  viewMatrix = camera.UpdateCameraPosition(input_Direction, mouseX, mouseY);
}

//////////////////////////////////////////////////////////////////////////////////
/// Deletes a GameAssetManager, in particular it will clean up any modifications
/// to the OpenGL state.
//////////////////////////////////////////////////////////////////////////////////

GameAssetManager::~GameAssetManager() {
  glDeleteProgram(program_token);
}

//////////////////////////////////////////////////////////////////////////////////
/// Adds a GameAsset to the scene graph.
//////////////////////////////////////////////////////////////////////////////////
void GameAssetManager::AddAsset(std::shared_ptr<GameAsset> the_asset) {
  draw_list.push_back(the_asset);
}

//////////////////////////////////////////////////////////////////////////////////
/// Draws each GameAsset in the scene graph.
//////////////////////////////////////////////////////////////////////////////////

void GameAssetManager::Draw() {
  for(auto ga: draw_list) {

    glm::mat4 Camera_Translate(1.0f);

    projectionMatrix_link = glGetUniformLocation(program_token, "projectionMatrix");
    translateMatrix_link = glGetUniformLocation(program_token, "translateMatrix");
    viewMatrix_link = glGetUniformLocation(program_token, "viewMatrix");

    projectionMatrix = glm::perspective(glm::radians(45.0f), (float) 640/(float)480, 0.1f, 1000.0f);

    glUniformMatrix4fv(projectionMatrix_link, 1, GL_FALSE, &projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrix_link, 1, GL_FALSE, &viewMatrix[0][0]);

    Camera_Translate = ga->GetModel();
    glUniformMatrix4fv(translateMatrix_link, 1, GL_FALSE, &Camera_Translate[0][0]);

    ga->Draw(program_token);
  }
}

//////////////////////////////////////////////////////////////////////////////////
/// When given the contents of a vertex shader and fragment shader
/// GameAssetManager::CreateGLProgram will compile and link them.  This
/// implementation will exit with -1 error if an error is detected.
///
/// @return the GL "token" referring to the gl program.
//////////////////////////////////////////////////////////////////////////////////
GLuint GameAssetManager::CreateGLProgram(std::string & vertex_shader
                                         , std::string & fragment_shader) {
  auto v_shader_token = CreateGLESShader(GL_VERTEX_SHADER, vertex_shader);
  auto f_shader_token = CreateGLESShader(GL_FRAGMENT_SHADER, fragment_shader);

  GLint program_ok;

  GLuint program = glCreateProgram();

  glAttachShader(program, v_shader_token);
  glAttachShader(program, f_shader_token);
  glLinkProgram(program);

  glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
  if (!program_ok) {
    std::cerr << "Failed to link shader program:" << std::endl;
    glDeleteProgram(program);
    exit(-1);
  }
  return program;
}

//////////////////////////////////////////////////////////////////////////////////
/// When given a type of shader to construct and the contents of a shader,
/// GameAssetManager::CreateGLESShader will create the shader or exit with
/// error -1.
///
/// @return the GL "token" for the requested shader.
//////////////////////////////////////////////////////////////////////////////////
GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader) {
  GLuint shader_token;
  GLint shader_ok;
  auto source = ReadShader(shader);

  if (!source.first)
    return 0;

  shader_token = glCreateShader(type);
  glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
  glCompileShader(shader_token);
  delete(source.first);

  glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);
  if (!shader_ok) {
    GLint maxLength = 0;
    glGetShaderiv(shader_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetShaderInfoLog(shader_token, maxLength, &maxLength, &errorLog[0]);

    //Provide the infolog in whatever manor you deem best.
    std::cerr << "Failed to compile " << shader << " with error code " << shader_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }

    glDeleteShader(shader_token); //Don't leak the shader.
    exit(-1);
  }
  return shader_token;
}

///////////////////////////////////////////////////////////////////////////////
/// ReadShader reads the contents of a file and packs it into a null termintated
/// GLchar * which is suitable for sending to OpenGL.
///
/// @return a pair consisting of the shader file contents and a holder for the
///         OpenGL "token".
///////////////////////////////////////////////////////////////////////////////
std::pair<GLchar *, GLint> GameAssetManager::ReadShader(std::string & shader) {
  std::ifstream input_file;
  GLint length;
  input_file.open(shader, std::ios::in);

  input_file.seekg(0, std::ios::end);  // go to the end of the file
  length = input_file.tellg();    // get length of the file
  input_file.seekg(0, std::ios::beg);  // go to beginning of the file

  GLchar * buffer = new GLchar[length+1];
  input_file.read(buffer, length);
  buffer[length+1]='\0';  // Ensure null terminated

  input_file.close();
  return std::make_pair(buffer, length);
}

//////////////////////////////////////////////////////////////////////////////////
/// Unimplemented copy constructor -- this means that the GameAssetManager
/// may not work as you'd expect when being copied.
//////////////////////////////////////////////////////////////////////////////////

GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) {
  // TODO: implement this
}

//////////////////////////////////////////////////////////////////////////////////
/// Unimplemented move constructor -- this unimplemented method violates the
/// C++11 move semantics for GameAssetManager.
//////////////////////////////////////////////////////////////////////////////////
GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager) {
  // TODO: implement this
}

//////////////////////////////////////////////////////////////////////////////////
/// Unimplemented assisgnment operator -- violates the expected semantics for
/// assignment in C++11.
//////////////////////////////////////////////////////////////////////////////////
void GameAssetManager::operator=(GameAssetManager) {
  // TODO: implement this
}


