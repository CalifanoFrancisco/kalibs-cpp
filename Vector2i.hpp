#ifndef VECTOR2I_HPP
#define VECTOR2I_HPP

struct Vector2i {
    int x, y;
    Vector2i(): x(0), y(0) {}
    Vector2i(const int _x, const int _y): x(_x), y(_y) {}
    inline bool operator==(const Vector2i& other) {
        return (x == other.x && y == other.y);
    }
};

#endif