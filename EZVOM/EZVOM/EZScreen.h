#ifndef EZSCREEN_H
#define EZSCREEN_H

#include <functional>
#include <iostream>
#include <IGameScreen.h>
#include <IMainGame.h>
#include <InputManager.h>
#include <GUI.h>
#include <Camera2D.h>
#include <GLSLProgram.h>
#include <SpriteBatch.h>

class EZScreen : public Feintgine::IGameScreen
{
    public:
        EZScreen();
        virtual ~EZScreen();
        EZScreen(Feintgine::Window * window);
        virtual void build() override;

        virtual void checkInput() override;

        virtual void destroy() override;

        virtual void draw() override;

        virtual int getNextScreenIndex() const override;

        virtual int getPreviousScreenIndex() const override;

        void initGUI();

        void initShader();


        void handleInput(Feintgine::InputManager & inputManager);

        virtual void onEntry() override;

        virtual void onExit() override;


	virtual void update(float deltaTime) override;
    protected:
    private:
        Feintgine::SpriteBatch m_spriteBatch;

        Feintgine::Camera2D m_camera;

        Feintgine::Window * m_window;

        Feintgine::GUI m_gui;

        Feintgine::GLSLProgram m_shader;
};

#endif // EZSCREEN_H
