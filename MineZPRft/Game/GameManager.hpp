/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  GameManager class declaration.
 */

#ifndef __GAME_GAMEMANAGER_HPP__
#define __GAME_GAMEMANAGER_HPP__

#include "GameWindow.hpp"
#include "Renderer/Renderer.hpp"
#include "Terrain/TerrainManager.hpp"
#include "Common/Timer.hpp"

#include <memory>

/**
 * Game manager class.
 */
class GameManager
{
public:
    /**
     * Run main game loop
     */
    void GameLoop();

    /**
     * Get pointer to used GameWindow object
     */
    GameWindow* GetWindow();

    /**
     * Choose to draw ray intersection from players view in next loop.
     */
    void DrawRay();

    /**
     * Get GameManager instance
     */
    static GameManager& GetInstance();

private:
    GameManager();
    GameManager(const GameManager&) = delete;
    GameManager(GameManager&&) = delete;
    GameManager& operator=(const GameManager&) = delete;
    GameManager& operator=(GameManager&&) = delete;
    ~GameManager();

    void CalculatePlayerChunk();

    Timer mFrameTimer;
    GamePlayer mPlayer;
    int mPlayerChunkX;
    int mPlayerChunkZ;
    GameWindow mWindow;
    Renderer& mRenderer;
    TerrainManager& mTerrain;
    bool mDrawRay;
};

#endif // __GAME_GAMEMANAGER_HPP__
