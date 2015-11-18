/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  Main function of the solution.
 */

#include "GameManager.hpp"

int main()
{
    GameManager::GetInstance().GameLoop();

    return 0;
}