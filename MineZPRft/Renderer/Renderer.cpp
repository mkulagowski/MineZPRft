/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  OpenGL Renderer definitions
 */

#include "Renderer.hpp"

#include "Common/Common.hpp"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Init(const RendererDesc& desc)
{
    UNUSED(desc);
}

void Renderer::AddMesh(const Mesh* mesh)
{
    UNUSED(mesh);
}

void Renderer::Draw() noexcept
{
}
