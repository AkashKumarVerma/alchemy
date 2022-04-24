#pragma once

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include "../utils/fileutils.h"

namespace alchemy { namespace graphics {
  class Shader {
  private:
      const char* m_VertPath;
      const char* m_FragPath;

    public:
      GLuint m_ShaderID;
      Shader(const char* vertPath, const char* fragPath);
      ~Shader();

      void enable();
      void disable();

    private:
      GLuint load();
  };
}}