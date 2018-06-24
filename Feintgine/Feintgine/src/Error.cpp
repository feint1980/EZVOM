#include "Error.h"
namespace Feintgine{
	extern void fatalError(std::string error)
	{

		int a;
		std::cout << error << std::endl;
		std::cin >> a;

		SDL_Quit();
		exit(20);


	}
}
