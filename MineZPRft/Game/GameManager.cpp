/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  GameManager class implementation.
 */

#include "GameManager.hpp"

GameManager::GameManager()
{
    // TODO: Add possibility to change the resolution
    mWindow.SetSize(800, 600);
    mWindow.SetTitle("MineZPRft Game Window");
}

GameManager::~GameManager()
{
    if (!mWindow.IsClosed())
        mWindow.Close();
}

GameManager& GameManager::GetInstance()
{
    static GameManager instance;
    return instance;
}

void GameManager::GameLoop()
{
    mWindow.Open();
    while (!mWindow.IsClosed())
        mWindow.ProcessMessages();
}

