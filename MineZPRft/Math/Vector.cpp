/**
 * @file
 * @author mkkulagowski (mkkulagowski(at)gmail.com)
 * @brief  Vector class implementation.
 */

#include "Vector.hpp"

#include <algorithm>
#include <cstring>

Vector::Vector()
    : Vector(0.0f)
{
}

Vector::Vector(float a)
{
    for (int i=0; i<4; ++i)
        f[i] = a;
}

Vector::Vector(float a, float b, float c, float d)
    : f{a,b,c,d}
{
}

Vector::~Vector()
{
}

Vector::Vector(const Vector& other)
{
    memcpy(f, other.f, sizeof(float) * 4);
}

Vector::Vector(Vector&& other)
    : Vector()
{
    std::swap(f, other.f);
}

const float* Vector::Data() const
{
    return f;
}

float Vector::Length() const
{
    Vector temp(*this);

    return sqrtf(temp % temp);
}

void Vector::Normalize()
{
    float len = Length();

    if (len)
        *this = *this / len;
}

Vector& Vector::operator= (const Vector& other)
{
    Vector tmp(other);
    *this = std::move(tmp);

    return *this;
}

Vector& Vector::operator= (Vector&& other)
{
    std::swap(f, other.f);

    return *this;
}

// Access operator
float Vector::operator[](int index) const
{
    return f[index];
}

// Addition
Vector& Vector::operator+(const Vector& other)
{
    for (int i = 0; i < 4; i++)
        f[i] += other.f[i];

    return *this;
}

Vector& Vector::operator+(float value)
{
    for (auto i : f)
        i += value;

    return *this;
}

// Subtraction
Vector& Vector::operator-(const Vector& other)
{
    for (int i = 0; i < 4; i++)
        f[i] -= other.f[i];

    return *this;
}

Vector& Vector::operator-(float value)
{
    for (auto i : f)
        i -= value;

    return *this;
}

// Multiplication
Vector& Vector::operator*(const Vector& other)
{
    for (int i = 0; i < 4; i++)
        f[i] *= other.f[i];

    return *this;
}

Vector& Vector::operator*(float value)
{
    for (auto i : f)
        i *= value;

    return *this;
}

// Division
Vector& Vector::operator/(const Vector& other)
{
    for (int i = 0; i < 4; i++)
        f[i] /= other.f[i];

    return *this;
}

Vector& Vector::operator/(float value)
{
    for (auto i : f)
        i /= value;

    return *this;
}

// Power
Vector& Vector::operator^(float value)
{
    for (auto i : f)
        i = pow(i, value);

    return *this;
}

// Dot product
float Vector::operator%(const Vector& other) const
{
    Vector tmp(*this);
    tmp = tmp * other;

    float result = 0;
    for (auto i : f)
        result += i;

    return result;
}

// Comparison
bool Vector::operator==(const Vector& other)
{
    for (int i=0; i<4; ++i)
        if (f[i] != other.f[i]) return false;
    return true;
}

bool Vector::operator<(const Vector& other)
{
    for (int i=0; i<4; ++i)
        if (f[i] >= other.f[i]) return false;
    return true;
}

bool Vector::operator>(const Vector& other)
{
    for (int i=0; i<4; ++i)
        if (f[i] <= other.f[i]) return false;
    return true;
}

bool Vector::operator<=(const Vector& other)
{
    for (int i=0; i<4; ++i)
        if (f[i] > other.f[i]) return false;
    return true;
}

bool Vector::operator>=(const Vector& other)
{
    for (int i=0; i<4; ++i)
        if (f[i] < other.f[i]) return false;
    return true;
}