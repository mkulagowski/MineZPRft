/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  GameWindow class implementation.
 */

#include "GameWindow.hpp"
#include "../Common/Common.hpp"

GameWindow::GameWindow()
{
}

void GameWindow::OnKeyPress(int key)
{
    std::string keyPressed = std::to_string(key);
    // wsad - movement (change playerPos)
    // q,e - switch cube types
    // shift - faster movement
}

void GameWindow::OnMouseDown(uint32_t button, int x, int y)
{
    UNUSED(button);
    UNUSED(x);
    UNUSED(y);
    // draw LAZOR to see where to create/delete cube
}

void GameWindow::OnMouseMove(int x, int y, int deltaX, int deltaY)
{
    UNUSED(x);
    UNUSED(y);
    UNUSED(deltaX);
    UNUSED(deltaY);
    // moves camera and movement direction
}

void GameWindow::OnMouseUp(uint32_t button)
{
    UNUSED(button);
    // TODO: if OnMouseDown is not triggered constantly while holding
    //       the button, then move the below over there
    // LMB - create cube
    // RMB - delete cube
}