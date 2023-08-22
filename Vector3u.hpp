#ifndef VECTOR3U_HPP
#define VECTOR3U_HPP

struct Vector3u {
    unsigned int x, y, z;
    Vector3u(): x(0), y(0), z(0) {}
    Vector3u(const unsigned int _x, const unsigned int _y, const unsigned int _z): x(_x), y(_y), z(_z) {}
    inline bool operator==(const Vector3u& other) {
        return (x == other.x && y == other.y && z == other.z);
    }
};


#endif