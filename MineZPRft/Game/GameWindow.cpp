/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  GameWindow class implementation.
 */

#include "GameWindow.hpp"

#include "Common/Common.hpp"
#include "Common/Logger.hpp"
#include "Math/Vector.hpp"
#include "GameKeycodes.hpp"
#include "Game/GameManager.hpp"

#include <functional>

GameWindow::GameWindow(GamePlayer* playerPtr)
    : mPlayerPtr(playerPtr)
{
}

void GameWindow::Update(double deltaTime) noexcept
{
    Vector playerShift;

    // get and calculate axes relative to Player's position and orientation
    // TODO probably there is no need to recalculate these vectors.
    //      They can be easily taken from Camera object hidden inside Player.
    //      Needs investigation and rewriting.
    const Vector& pos = mPlayerPtr->GetPosition();
    const Vector& dir = mPlayerPtr->GetDirection();
    const Vector& up = mPlayerPtr->GetUp();

    Vector right = dir.Cross(up);
    right.Normalize();

    if (IsKeyPressed(Key::W))
        playerShift += dir;
    if (IsKeyPressed(Key::S))
        playerShift -= dir;
    if (IsKeyPressed(Key::A))
        playerShift -= right;
    if (IsKeyPressed(Key::D))
        playerShift += right;
    if (IsKeyPressed(Key::R))
        playerShift += up;
    if (IsKeyPressed(Key::F))
        playerShift -= up;

    playerShift.Normalize();
    playerShift *= static_cast<float>(deltaTime);

    if (IsKeyPressed(Key::LShift))
        playerShift *= 20.0f;

    mPlayerPtr->SetPosition(pos + playerShift);
    mPlayerPtr->Update();
}

void GameWindow::OnKeyPress(int key)
{
    // TODO:
    //   q,e - switch cube types

    if (key == Key::P)
    {
        const Vector& pos = mPlayerPtr->GetPosition();
        LOG_I("Player position: " << pos);
    }

    if (key == Key::Enter && IsKeyPressed(Key::Alt))
    {
        SetFullscreenMode(!GetFullscreenMode());
    }
}

void GameWindow::OnMouseDown(uint32_t button, int x, int y)
{
    UNUSED(x);
    UNUSED(y);

    if (button == Mouse::RMB)
        GameManager::GetInstance().DrawRay();
    // draw LAZOR to see where to create/delete cube
}

void GameWindow::OnMouseMove(int x, int y, int deltaX, int deltaY)
{
    UNUSED(x);
    UNUSED(y);

    // scale the deltas to produce a rotation angle
    if (IsMouseButtonDown(Mouse::LMB))
    {
        float angleX = -deltaX * 0.005f;
        float angleY = deltaY * 0.005f;

        mPlayerPtr->ShiftRotationX(angleX);
        mPlayerPtr->ShiftRotationY(angleY);
    }
}

void GameWindow::OnMouseUp(uint32_t button)
{
    UNUSED(button);
    // TODO: if OnMouseDown is not triggered constantly while holding
    //       the button, then move the below over there
    // LMB - create cube
    // RMB - delete cube
}

void GameWindow::OnResize(uint32_t width, uint32_t height)
{
    Renderer::GetInstance().ResizeViewport(width, height);
}
