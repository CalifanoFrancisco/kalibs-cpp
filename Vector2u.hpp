#ifndef VECTOR2U_HPP
#define VECTOR2U_HPP

struct Vector2u {
    unsigned int x, y;
    Vector2u(): x(0), y(0) {}
    Vector2u(const unsigned int _x, const unsigned int _y): x(_x), y(_y) {}
    inline bool operator==(const Vector2u& other) {
        return (x == other.x && y == other.y);
    }
};

#endif