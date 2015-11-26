/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Commonly used definitions on Linux
 */

#include "../Common.hpp"

#include <string.h>

std::string GetLastErrorString()
{
    return strerror(errno);
}
