/**
* @file
* @author mkkulagowski (mkkulagowski(at)gmail.com)
* @brief  UTF-related functions implementation.
*/

#pragma once

#include <vector>
#include <Windows.h>

#include "UTFfuncs.hpp"

/**
* Convert from UTF16 to UTF8
* @param string in UTF16
* @return string in UTF8
*/
static std::string UTF16ToUTF8(const std::wstring &s);

/**
* Convert from UTF8 to UTF16
* @param string in UTF8
* @return string in UTF16
*/
static std::wstring UTF8ToUTF16(const std::string &s);




static std::string UTF16ToUTF8(const std::wstring &s)
{
    const int size = ::WideCharToMultiByte(CP_UTF8, 0, s.c_str(), -1, NULL,
                                           0, 0, NULL);

    std::vector<char> buf(size);
    int charsConverted = ::WideCharToMultiByte(CP_UTF8, 0, s.c_str(), -1,
                                               &buf[0], size, 0, NULL);
    if (charsConverted == 0)
        return std::string();

    return std::string(buf.data());
}

static std::wstring UTF8ToUTF16(const std::string &s)
{
    int strSize = static_cast<int>(s.size());
    size_t charsNeeded = ::MultiByteToWideChar(CP_UTF8, 0, s.data(), strSize,
                                               NULL, 0);
    if (charsNeeded == 0)
        return std::wstring();

    std::vector<wchar_t> buffer(charsNeeded);
    int bufferSize = static_cast<int>(buffer.size());
    int charsConverted = ::MultiByteToWideChar(CP_UTF8, 0, s.data(), strSize,
                                               &buffer[0], bufferSize);
    if (charsConverted == 0)
        return std::wstring();

    return std::wstring(&buffer[0], charsConverted);
}