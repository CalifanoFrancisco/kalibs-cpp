#ifndef VECTOR2_HPP
#define VECTOR2_HPP

template <typename T> 
struct Vector2 {
    T x, y;
    Vector2(): x(T()), y(T()) { }
    Vector2(const T _x, const T _y): x(_x), y(_y) { }
    inline bool operator==(const Vector2<T>& other) {
        return (x == other.x && y == other.y);
    }
};

#endif