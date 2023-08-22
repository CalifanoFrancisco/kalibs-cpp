#ifndef VECTOR3I_HPP
#define VECTOR3I_HPP

struct Vector3i {
    int x, y, z;
    Vector3i(): x(0), y(0), z(0) {}
    Vector3i(const int _x, const int _y, const int _z): x(_x), y(_y), z(_z) {}
    inline bool operator==(const Vector3i& other) {
        return (x == other.x && y == other.y && z == other.z);
    }
};


#endif