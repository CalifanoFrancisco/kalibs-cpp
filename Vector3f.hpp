#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

struct Vector3f {
    float x, y, z;
    Vector3f(): x(0), y(0), z(0) {}
    Vector3f(const float _x, const float _y, const float _z): x(_x), y(_y), z(_z) {}
    inline bool operator==(const Vector3f& other) {
        return (x == other.x && y == other.y && z == other.z);
    }
};

#endif