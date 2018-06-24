#ifndef SCREENLIST_H
#define SCREENLIST_H
#include "IGameScreen.h"

#include <vector>

namespace Feintgine
{
	class IMainGame;

	class IGameScreen;

	class ScreenList
	{
	public:
		ScreenList(IMainGame * game);
		~ScreenList();
		IGameScreen * moveNext();
		IGameScreen * movePrevious();

		IGameScreen * getCurrentGameScreen();

		void setScreen(int nextScreen);

		void addScreen(IGameScreen * newScreen);

		void destroy();

		void onExit();



	protected:
		IMainGame * m_game = nullptr;
		std::vector<IGameScreen * > m_screens;
		int m_currentScreenIndex = -1;

	};

}
#endif // SCREENLIST_H
