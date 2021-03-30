//
//  Middle1.cpp
//
//
//  Created by Юрий Филиппов on 31.03.2021.
//

#include <iostream>
#include <cmath>

class Vector
{
public:
    Vector():x(0),y(0),z(0)
    {
    }
    Vector (float _x, float _y, float _z):
    x(_x),
    y(_y),
    z(_z)
    {
    }
    
    operator float()
    {
        return sqrt(x*x + y*y +z*z);
    }
    
    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator-(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v, float f);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);
    friend bool operator>(const Vector& x, const Vector& y);
    
private:
    float x, y, z;
    
};

bool operator>(const Vector& x, const Vector& y)
{
    return false;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector operator*(const Vector& v, float f)
{
    return Vector(f * v.x, f * v.y, f * v.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << '(' << v.x << ',' << v.y << ',' << v.z << ')';
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}


int main()
{
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;
    v3 = v1 + v2;
    std::cout << v3 << std::endl;
    std::cout << "v3 length " << float(v3) << std::endl;
    std::cout << "v3 * 5 = " << v3*5.f << std::endl;
    std::cout << "v3 - (1,1,1) = " << v3 - Vector(1, 1, 1) << std::endl;
    std::cin >> v3;
    std::cout << v3 << std::endl;
}

