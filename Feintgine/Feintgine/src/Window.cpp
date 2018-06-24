#include "Window.h"
namespace Feintgine{

    Window::Window()
    {

    }

    int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int windowFlag)
    {

            if (glContext)
            {
                std::cout << "destroy old context \n";
                SDL_GL_DeleteContext(glContext);
            }
            SDL_DisplayMode DM;
            SDL_GetDesktopDisplayMode(0, &DM);
            //SDL_GetCurrentDisplayMode(0, &DM);
            int Width = DM.w;
            int Height = DM.h;
            m_screenHeight = screenHeight;
            m_screenWidth = screenWidth;
            m_resolutionWidth = Width;
            m_resolutionHeight = Height;
            if (windowFlag & FULLSCREEN)
            {
                std::cout << "calculate new solution \n";
                m_screenWidth = m_resolutionWidth;
                m_screenHeight = m_resolutionHeight;
            }

            m_aspectRatio =  (float)m_screenWidth /(float)m_resolutionWidth;
            std::cout << "new aspect is " << m_aspectRatio << "\n";

            Uint32 flags = SDL_WINDOW_OPENGL;
            if (windowFlag & INVISIBLE)
            {
                flags |= SDL_WINDOW_HIDDEN;

            }
            if (windowFlag & FULLSCREEN)
            {
                flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
            }

            if (windowFlag & BORDERLESS)
            {
                flags |= SDL_WINDOW_BORDERLESS;
            }


            _sdlWindow = SDL_CreateWindow(windowName.c_str(), 10, 30, screenWidth, screenHeight, 0);



            if (_sdlWindow == nullptr)
            {
                printf("SDL_Init failed: %s\n", SDL_GetError());
                fatalError("ko tao dc , chac thieu RAM !, chac card cui` hoac ko co card, lol ngheo vcl");
            }

            glContext = SDL_GL_CreateContext(_sdlWindow);
            if (glContext == nullptr)
            {
                fatalError("ko tao dc context OPENGL , chac card cui` ! ");
            }
            GLenum error = glewInit();
            if (error != GLEW_OK)
            {
                fatalError("glew co van de ");
            }
            std::cout << "context is " << glContext << "\n";

            glClearColor(0, 0, 0, 0);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            return 0;
    }

    void Window::swapBuffer()
	{

		SDL_GL_SwapWindow(_sdlWindow);
	}
	void Window::loadContext(SDL_GLContext context)
	{
		glContext = context;
		SDL_GL_MakeCurrent(_sdlWindow, glContext);
		std::cout << "context load is " << glContext << "\n";
	}

	void Window::deleteWindow()
	{

		SDL_DestroyWindow(_sdlWindow);
	}

	void Window::saveContext(SDL_GLContext context)
	{
		m_savedContext = context;
	}

	void Window::storageCamPos(glm::vec2 pos)
	{
		m_cameraStorePos = pos;
	}

    Window::~Window()
    {
        //dtor
    }

}
