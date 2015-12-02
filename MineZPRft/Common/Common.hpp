/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Commonly used declarations.
 */

#ifndef __COMMON_COMMON_HPP__
#define __COMMON_COMMON_HPP__

#include <string>

#ifdef WIN32
#include <Windows.h>
#endif //WIN32


// Macro for unused parameters to supress warnings in skeletons
#define UNUSED(x) (void)x


/**
 * Acquire last error String from OS-specific API.
 *
 * @return Last error in string.
 */
std::string GetLastErrorString();

#endif // __COMMON_COMMON_HPP__