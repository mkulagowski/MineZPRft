/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Renderer's Shader definitions
 */

#include "Shader.hpp"

#include "Common/Common.hpp"

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::Init(const ShaderDesc& desc)
{
    UNUSED(desc);
}

void Shader::MakeCurrent() noexcept
{
}
