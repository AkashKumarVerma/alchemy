#include "src/graphics/window.h"


int main() {
  using namespace alchemy;
  using namespace graphics;

  Window window("Alchemy ~", 960, 540);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  while (!window.closed()) {
    window.clear();
     
    double x, y;
    window.getMousePosition(x, y);
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    if (window.isKeyPressed(GLFW_KEY_A)) {
      std::cout << "A PRESSED!" << std::endl;
    }

    if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
      std::cout << "Mouse PRESSED!" << std::endl;
    }

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