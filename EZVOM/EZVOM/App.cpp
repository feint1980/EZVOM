#include "App.h"

App::App()
{
}


App::~App()
{
	std::cout << "exit \n";
}


void App::onInit()
{

    std::cout << "Init here \n";
    configureScreen("Feint Editor", 600, 600, 0,false);
}


void App::addScreen()
{
    m_ez = std::make_unique<EZScreen>(&m_window);
	//m_screenList->setScreen(m_selectScreen->getScreenIndex());
	std::cout << " called here \n";
	m_screenList->addScreen(m_ez.get());
	m_screenList->setScreen(m_ez->getScreenIndex());

}
void App::onExit()
{

}
