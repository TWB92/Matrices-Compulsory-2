#pragma once

class Vector3D
{
public:
    Vector3D();
    Vector3D(double _x, double _y, double _z);
    
    double mag();
    Vector3D scale(double in);
    Vector3D normalize();
    double dotProduct(Vector3D i);
    Vector3D crossProduct(Vector3D i);
    
    Vector3D& operator+=(const Vector3D& rhs);
    Vector3D& operator-=(const Vector3D& rhs);
    friend Vector3D& operator+(const Vector3D& lhs, const Vector3D& rhs);
    friend Vector3D& operator-(const Vector3D& lhs, const Vector3D& rhs);
    
private:
    double x;
    double y;
    double z;
};
