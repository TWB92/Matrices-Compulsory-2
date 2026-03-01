#include "Vector3D.h"

#include <cmath>

// Contains functionality which is not intended for Compulsory 2 tests, as I've made this class to be replicated and reused at a later time.

// I made use of a Vector2D class we made last semester as reference to make some of the member functions

Vector3D::Vector3D()
{
    // Default constructor, returns a zero vector
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(double _x, double _y, double _z)
{
    // Constructs a vector.
    x = _x;
    y = _y;
    z = _z;
}

double Vector3D::mag()
{
    // Magnitude of vector.
    return sqrtl(x*x + y*y + z*z);
}

Vector3D Vector3D::scale(double in)
{
    // Scales a vector with scalar.
    return {x * in, y * in, z * in};
}

Vector3D Vector3D::normalize()
{
    // Returns vector with the same direction but with a magnitude of 1.
    return scale(1/mag());
}

double Vector3D::dotProduct(Vector3D i)
{
    // Dot product of two vectors.
    return x*i.x + y*i.y + z*i.z;
}

Vector3D Vector3D::crossProduct(Vector3D i)
{
    // Returns a cross product of two vectors.
    return {
        y*i.z - z*i.y,
        z*i.x - x*i.z,
        x*i.y - y*i.x
    };
}

// Me trying something new and learning operator overloading.
Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    // Definition of += operator.
    x+=rhs.x;
    y+=rhs.y;
    z+=rhs.z;
    
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    // Definition of -= operator.
    x-=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
    
    return *this;
}

Vector3D& operator+(const Vector3D& lhs, const Vector3D& rhs)
{
    // Definition of + operator, using +=.
    Vector3D lhs1(lhs);
    return lhs1 += rhs;
}

Vector3D& operator-(const Vector3D& lhs, const Vector3D& rhs)
{
    // Definition of - operator, using -=.
    Vector3D lhs1(lhs);
    return lhs1 -= rhs;
}
