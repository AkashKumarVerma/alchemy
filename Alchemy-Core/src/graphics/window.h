#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace alchemy { namespace graphics {

	#define MAX_KEYS    1024
	#define MAX_BUTTONS 32

	class Window {

		private:
			int  m_width;
			int  m_height;
			bool m_closed;
			const char* m_title;
			GLFWwindow* m_window;

			bool   m_keys[MAX_KEYS];
			bool   m_mouseButtons[MAX_BUTTONS];
			double m_mouseX, m_mouseY;

		public:
			Window(const char* title, int width, int height);
			~Window();
			void update();
			void clear() const;
			bool closed() const;

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;

		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cusror_position_callback(GLFWwindow* window, double xpos, double ypos);
	};

}}