/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Definition of OGL_GET_EXTENSION macro
 */

#ifndef __COMMON_GETEXTENSION_HPP__
#define __COMMON_GETEXTENSION_HPP__

#include <iostream>

#ifdef WIN32
#define GET_PROC_ADDRESS(x) wglGetProcAddress( #x )
#elif defined(__linux__) | defined(__LINUX__)
#include <GL/glx.h>
#define GET_PROC_ADDRESS(x) glXGetProcAddress((const GLubyte*) #x )
#else
#error "Target platform not supported."
#endif // WIN32

#ifndef OGL_GET_EXTENSION
/**
 * Get an OpenGL extension using wglGetProcAddress or glXGetProcAddress.
 *
 * The functions return a nullptr when the extension is not available. When such situation
 * occurs, appropriate information is logged and allExtensionsAvailable is set to false.
 */
#define OGL_GET_EXTENSION(type, proc)                                                       \
do {                                                                                        \
    proc = reinterpret_cast<type>(GET_PROC_ADDRESS(proc));                                  \
    if (!proc)                                                                              \
    {                                                                                       \
        std::cerr << "Unable to retrieve " #proc " extension function.";                    \
        allExtensionsAvailable = false;                                                     \
    }                                                                                       \
} while(0)
#endif // OGL_GET_EXTENSION

#endif // __COMMON_GETEXTENSION_HPP__