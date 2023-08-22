#ifndef VECTOR3_HPP
#define VECTOR3_HPP

template <typename T> 
struct Vector3 
{
    T x, y, z;
    Vector3(): x(T()), y(T()), z(T()) {}
    Vector3(const T _x, const T _y, const T _z): x(_x), y(_y), z(_z) {}
    inline bool operator==(const Vector3<T>& other) {
        return (x == other.x && y == other.y && z == other.z);
    }
};

#endif