/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Renderer's Camera definitions
 */

#include "Camera.hpp"

#include "../Common/Common.hpp"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Init(const CameraDesc& desc)
{
    UNUSED(desc);
}

void Camera::Update(const CameraUpdateDesc& request) noexcept
{
    UNUSED(request);
}
