#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H


#include <string>
#include <GL/glew.h>

namespace Feintgine {

	//This class handles the compilation, linking, and usage of a GLSL shader program.
	//Reference: http://www.opengl.org/wiki/Shader_Compilation
	class GLSLProgram
	{
	public:
		GLSLProgram();
		~GLSLProgram();

		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

		void compileShadersFromSource(const char* vertexSource, const char* fragmentSource);

		void linkShaders();

		void addAttribute(const std::string& attributeName);

		GLint getUniformLocation(const std::string& uniformName);



		int getNumAttribute() const { return _numAttributes; }

		void use();
		void unuse();

		GLuint getID() const { return _programID; }

		void dispose();
	private:

		int _numAttributes;

		void compileShader(const char* source, const std::string& name, GLuint id);

		GLuint _programID;

		GLuint _vertexShaderID;
		GLuint _fragmentShaderID;
	};

}

#endif // GLSLPROGRAM_H
