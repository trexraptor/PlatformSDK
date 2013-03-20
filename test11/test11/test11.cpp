// test11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "SDL-1.2.15\include\SDL.h"
//#include <conio.h>


#define PAGE_UP     73
#define HOME        71
#define END         79
#define PAGE_DOWN   81
#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define F1          59
#define F2          60
#define F3          61
#define F4          62
#define F5          63
#define F6          64
#define F7          65
#define F8          66
#define F9          67
#define F10         68

class Game
{
public:
    bool Init();
    void Run();
    bool DeInit();

protected:
    enum enState { InitState = 0,
                   InProgressState,
                   PauseState,
                   OverState,
                   DeInitState};

    virtual void Update();
    virtual void Draw();
    virtual void HandleControl();
    
    bool ChangeState(enState);
    enState GetState();

    enState m_currentState;
    ///
    
    int m_test;
};

bool Game::Init()
{
    int result = SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);

    if ( screen == NULL )
    {
        std::cout << "resolution Error" << std::endl;
    }

    m_currentState = enState::InitState;
    m_test = 0;
    return true;
}
bool Game::DeInit()
{
    m_currentState = enState::DeInitState;
    SDL_Quit();
    return true;
}

bool Game::ChangeState(enState state)
{
    m_currentState = state;
    return true;
}

Game::enState Game::GetState()
{
    return m_currentState;
}

void Game::Run()
{
    this->ChangeState(enState::InProgressState);
    while(this->GetState() == enState::InProgressState)
    {
        this->HandleControl();
        this->Update();
        this->Draw();
    }
}

void Game::HandleControl()
{
    SDL_Event event;
 
    while ( SDL_PollEvent(&event) ) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                printf("Mouse moved by %d,%d to (%d,%d)\n", 
                       event.motion.xrel, event.motion.yrel,
                       event.motion.x, event.motion.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("Mouse button %d pressed at (%d,%d)\n",
                       event.button.button, event.button.x, event.button.y);
                break;
            case SDL_KEYDOWN:
                //event.key.state
                break;
            case SDL_QUIT:
                exit(0);
        }
    }
}
void Game::Update()
{
//    m_test++;
}

void Game::Draw()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
    Game game;
    game.Init();
    game.Run();
    game.DeInit();
    return 0;
}


