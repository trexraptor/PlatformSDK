#include "Game.h"

CGame::CGame(IGameInput* pInput, IGameEngine* pEngine, IGameRender* pRender) :
m_pInput(pInput), m_pEngine(pEngine), m_pRender(pRender)
{

}



void CGame::Run()
{
    this->ChangeState(enGameState::InProgressState);
    while(this->GetState() == enGameState::InProgressState)
    {
        this->HandleControl();
        this->Update();
        this->Draw();
    }
}

