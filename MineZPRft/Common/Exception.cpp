/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  Exception class definition.
 */

#include "Exception.hpp"


Exception::Exception()
    : mMsg("Exception")
{
}

Exception::Exception(const std::string& file, int line, const std::string& msg)
    : Exception()
{
    Init(file, line, msg);
}

Exception::~Exception()
{
}

const char* Exception::what() const noexcept
{
    return mMsg.c_str();
}

void Exception::Init(const std::string& file, int line, const std::string& msg)
{
    // Message format: <exception_type> at <file>@<line>: <message_from_ctor>
    mMsg += " at " + file + '@' + std::to_string(line) + ": " + msg;
}
