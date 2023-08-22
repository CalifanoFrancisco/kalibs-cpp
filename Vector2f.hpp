#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

struct Vector2f {
    float x, y;
    Vector2f(): x(0), y(0) {}
    Vector2f(const float _x, const float _y): x(_x), y(_y) {}
    inline bool operator==(const Vector2f& other) {
        return (x == other.x && y == other.y);
    }
};

#endif