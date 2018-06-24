#include <SDL.h>
#include "Feintgine.h"
namespace Feintgine
{
typedef __SIZE_TYPE__ size_t;

	int initFeint()
	{
		//if (!SDL_WasInit(0))
		//{
			SDL_Init(SDL_INIT_EVERYTHING);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//	}

		return 0;
	}
}


