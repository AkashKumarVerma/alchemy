#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"

int main() {
  using namespace alchemy;
  using namespace graphics;
  using namespace maths;

  Window window("Alchemy ~", 960, 540);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


  GLfloat vertices[] = {
    0,  0, 0,
    15, 0, 0,
    0,  8, 0,
  };

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  mat4 ortho = mat4::orthographic(00.f, 16.f, 0.0f, 9.0f, -1.0f, 1.0f);

  Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
  shader.enable();
  glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);


  while (!window.closed()) {
    window.clear();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    window.update();
  }

  return 0;
}