#include "EZScreen.h"

EZScreen::EZScreen()
{
    //ctor
}

EZScreen::EZScreen(Feintgine::Window * window)
{
	m_window = window;
	m_screenIndex = 9;
}

EZScreen::~EZScreen()
{
    //dtor
}

void EZScreen::build()
{

}

void EZScreen::checkInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		m_gui.onSDLEvent(evnt);
		//m_camera.handleInput(m_game->getInputManager(), evnt);
		m_game->onSDLEvent(evnt);
	}
	//handleInput(m_game->getInputManager());
}

void EZScreen::destroy()
{

}



void EZScreen::draw()
{

	glViewport(0, 0, 1600, 900);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	m_shader.use();

	GLint textureUniform = m_shader.getUniformLocation("mySampler");
	glUniform1i(textureUniform, 0);
	glActiveTexture(GL_TEXTURE0);

	// Camera matrix

	GLint pUniform = m_shader.getUniformLocation("P");
	glm::mat4 objectsMatrix = m_camera.getCameraMatrix();
	glUniformMatrix4fv(pUniform, 1, GL_FALSE, &objectsMatrix[0][0]);

	m_spriteBatch.begin();
	//m_currentTexture.draw(m_spriteBatch);

	//testObject.draw(m_spriteBatch);
	//bg.draw(m_spriteBatch);
	m_spriteBatch.end();
	m_spriteBatch.renderBatch();



	m_shader.unuse();


	glDisable(GL_SCISSOR_TEST);
	//m_textRenderer.renderText(m_camera, L"Đây là 1 vài dòng text để test", m_camera.convertScreenToWorld(m_game->getInputManager().getMouseCoords()), Feintgine::Color(255, 255, 255, 255), 1, ALIGN_FT_CENTER);


	m_gui.draw();


}


int EZScreen::getNextScreenIndex() const
{
	return -1;
}

int EZScreen::getPreviousScreenIndex() const
{
	return -1;
}

void EZScreen::onEntry()
{


	//SetConsoleOutputCP(65001);



	m_spriteBatch.init();

	//m_textRenderer.init();

	m_camera.init(m_window->getScreenWidth() , m_window->getScreenHeight(),7);
	m_camera.setScale(1);
	m_camera.setPosition(glm::vec2(0));
	m_camera.update();

	//std::cout << "testing service " << feint_common::Instance()->getFileNameFromPath("E:/template/my_last/GC3/Editor/Assets") << "\n";
	//Feintgine::SpriteManager::Instance()->loadFromDirectory("E:/template/my_last/GC3/Editor/Assets",0);


	//Feintgine::SpriteManager::Instance()->printPacketList();
	//testObject.init(Feintgine::SpriteManager::Instance()->getSprite("green.xml/system_02.png"), glm::vec2(0), glm::vec2(1), Feintgine::Color(255, 255, 255, 255));


	std::cout << "check property of F_EmptyObject\n";

//	Feintgine::SpriteManager::Instance()->getSpritePacketByName("Golden.xml").writeToImageset("Golden.imageset");





	//std::cout << "UV -> " << glm::to_string(testObject.getSprite().getUV()) << "\n";
	initGUI();
	initShader();

	//calculate round shape for 16x9 9/16 = 0.5625
	float m_spine = 0.4;
	//m_spriteDisplayer.init(&m_gui, glm::vec2(0.01), glm::vec2(m_spine*0.5625,m_spine),4,4);

	//m_spriteDisplayer.loadTotalList();







}

void EZScreen::onExit()
{
	m_shader.dispose();
	m_gui.destroy();
}


void EZScreen::update(float deltaTime)
{
	m_camera.update();

	m_gui.update();
}

void EZScreen::initGUI()
{
	m_gui.init("GUI");



	m_gui.loadScheme("TaharezLook.scheme");
	m_gui.loadScheme("AlfiskoSkin.scheme");
	m_gui.loadScheme("OgreTray.scheme");
	m_gui.loadScheme("Golden.scheme");
	m_gui.setFont("DejaVuSans-12");

	//m_gui.setMouseCursor("AlfiskoSkin/MouseArrow");




	//m_gui.showMouseCursor();
	//SDL_ShowCursor(1);
}

void EZScreen::initShader()
{
	m_shader.compileShaders("Shaders/editor.vert", "Shaders/editor.frag");
	m_shader.addAttribute("vertexPosition");
	m_shader.addAttribute("vertexColor");
	m_shader.addAttribute("vertexUV");
	m_shader.linkShaders();
	m_alpha = 1;
}

void EZScreen::handleInput(Feintgine::InputManager & inputManager)
{
	if (inputManager.isKeyPressed(SDLK_ESCAPE))
	{
		m_currentState = Feintgine::ScreenState::EXIT_APPLICATION;
	}
}
