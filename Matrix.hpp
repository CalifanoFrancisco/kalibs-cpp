#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Iterator.hpp"

template 
<
    typename T,
    size_t   X = 1,
    size_t   Y = 1,
    size_t   Z = 1
> 
class Matrix 
{
public:
    const size_t x = X;
    const size_t y = Y;
    const size_t z = Z;

    Matrix() 
    {
        m_size = X * Y * Z;
        m_elements = new T[size()];
    }

    Matrix(const T& element)
        : Matrix()
    {
        this->fill(element);
    }

    ~Matrix() {
        delete[] m_elements;
    }

    inline int size() const {
        return m_size;
    }

    inline T& operator[](const size_t index) {
        return m_elements[index];
    }

    inline void fill(const T& element) {
        for (int i = 0; i < m_size; i++) 
            m_elements[i] = element;
    }

    Iterator<T> begin() const {
        return Iterator(&m_elements[0]);
    }

    Iterator<T> end() const {
        return Iterator(&m_elements[m_size]);
    }

private:
    T*     m_elements = nullptr;
    size_t m_size;
    
};

#endif
