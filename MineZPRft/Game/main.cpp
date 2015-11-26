/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  Main function of the solution.
 */

#include "GameManager.hpp"

#include "Common/FileSystem.hpp"

int main()
{
    // Navigate to project root directory
    FS::ChangeDirectory(FS::GetExecutableDir() + "/../../..");

    GameManager::GetInstance().GameLoop();

    return 0;
}