/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Renderer Mesh definitions
 */

#include "Mesh.hpp"

#include "Common/Common.hpp"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::Init(const MeshDesc& desc)
{
    UNUSED(desc);
}

void Mesh::Update(const MeshUpdateDesc& desc) noexcept
{
    UNUSED(desc);
}
