#ifndef APP_H
#define APP_H

#include <IMainGame.h>
#include "EZScreen.h"

class App : public Feintgine::IMainGame
{
public:
	App();
	~App();

	virtual void onInit() override;
	virtual void addScreen() override;
	virtual void onExit() override;

private:


    std::unique_ptr<EZScreen> m_ez = nullptr;


};
#endif // APP_H
