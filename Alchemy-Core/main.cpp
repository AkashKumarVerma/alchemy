#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main() {
  using namespace alchemy;
  using namespace graphics;
  using namespace maths;

  Window window("Alchemy ~", 960, 540);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  
  vec2 vec2a(1.0f, 2.0f);
  vec2 vec2b(2.0f, 4.0f);

  vec3 vec3a(2.0f, 3.0f, 4.0f);
  vec3 vec3b(2.0f, 4.0f, 3.0f);
  
  vec4 vec4a(1.0f, 2.0f, 3.0f, 4.0f);
  vec4 vec4b(1.0f, 2.0f, 3.0f, 4.0f);

  vec2 c2 = vec2a + vec2b;
  vec3 c3 = vec3a + vec3b;
  vec4 c4 = vec4a + vec4b;

  mat4 position = mat4::translation(vec3(2, 3, 4));

  position *= mat4::identity();

  vec4 column = position.columns[3];
  std::cout << column << std::endl;

  while (!window.closed()) {
    window.clear();

  #if 1
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f,  0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f( 0.5f, -0.5f);
    glEnd();
  #else
    glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
  #endif

    window.update();
  }

  return 0;
}