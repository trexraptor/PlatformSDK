//#ifndef GAME_H
//#define GAME_H
#pragma once

class IGameRender
{
public:
    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void DeInit() = 0;
};

class IGameInput
{
public:
    virtual void Init() = 0;
    virtual void ProcessInput() = 0;
    virtual void DeInit() = 0;
};

class IGameEngine
{
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void DeInit() = 0;
};

class CGame
{
public:

    CGame(IGameInput*, IGameEngine*, IGameRender*);
    virtual bool Init();
    void Run();
    bool DeInit();
    virtual ~CGame();

protected:

    enum enGameState { InitState = 0,
                       InProgressState,
                       PauseState,
                       OverState,
                       DeInitState};

    virtual void Update();
    virtual void Draw();
    virtual void HandleControl();
    
    bool ChangeState(enGameState);
    enGameState GetState();

    IGameEngine* m_pEngine;
    IGameInput* m_pInput;
    IGameRender* m_pRender;
    
    enGameState m_currentState;
};

//#endif