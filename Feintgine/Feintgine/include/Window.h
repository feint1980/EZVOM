#ifndef WINDOW_H
#define WINDOW_H
typedef __SIZE_TYPE__ size_t;
#include <SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include "Error.h"
#include <glm/glm.hpp>

namespace Feintgine{

enum WindowFlags{ INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };
class Window
{
    public:
        Window();
        virtual ~Window();

        int create(std::string windowName, int screenWidth, int screenHeight, unsigned int windowFlag);
        void swapBuffer();
		void loadContext(SDL_GLContext context);
		void deleteWindow();
		int getScreenWidth(){ return m_screenWidth; }
		int getScreenHeight(){ return m_screenHeight; }
		int getResolutionWidth() const { return m_resolutionWidth; }
		int getResolutionHeight() const { return m_resolutionHeight; }
		float getAspect() const { return m_aspectRatio; }
		void saveContext(SDL_GLContext context);
		SDL_GLContext getSavedContext() const { return m_savedContext; }
		SDL_GLContext getGLContext() const { return glContext; }
		void storageCamPos(glm::vec2 pos);
		glm::vec2 getStoragedCam() const { return m_cameraStorePos; }

    protected:
    private:
        SDL_GLContext glContext;
        SDL_Window *_sdlWindow;
		int m_screenWidth;
		int m_screenHeight;
		int m_resolutionWidth;
		int m_resolutionHeight;
		float m_aspectRatio;

		glm::vec2 m_cameraStorePos;
		SDL_GLContext m_savedContext;
};

}


#endif // WINDOW_H
