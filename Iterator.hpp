#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>  // for std::ptrdiff_t
#include <iterator> // for std::random_access_iterator_tag

template <typename T> class Iterator 
{

public:
    using value_type        = T;
    using pointer           = value_type*;
    using reference         = value_type&;
    using difference_type   = std::ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    Iterator(): m_ptr(nullptr) {}
    
    Iterator(pointer ptr): m_ptr(ptr) {}

    reference operator*() const {
        return *m_ptr;
    }

    pointer operator->() const {
        return m_ptr;
    }

    reference& operator[](difference_type n) const {
        return *(m_ptr + n); // m_ptr[n];
    }

    Iterator& operator++() {
        ++m_ptr;
        return *this;
    }

    Iterator  operator++(int) {
        Iterator tmp = *this; 
        ++m_ptr;
        return tmp;
    }

    Iterator& operator--() {
        --m_ptr;
        return *this;
    }

    Iterator  operator--(int) {
        Iterator tmp = *this;
        --m_ptr;
        return tmp;
    }

    Iterator& operator+=(difference_type n) {
        m_ptr += n;
        return *this;
    }

    Iterator& operator-=(difference_type n) {
        m_ptr -= n;
        return *this;
    }

    friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
        return lhs.m_ptr == rhs.m_ptr;
    }
    friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const Iterator& lhs, const Iterator& rhs) {
        return lhs.m_ptr < rhs.m_ptr;
    }
    friend bool operator>(const Iterator& lhs, const Iterator& rhs) {
        return rhs < lhs;
    }
    friend bool operator<=(const Iterator& lhs, const Iterator& rhs) {
        return !(rhs < lhs);
    }
    friend bool operator>=(const Iterator& lhs, const Iterator& rhs) {
        return !(lhs < rhs);
    }
    friend Iterator operator+(const Iterator& it, difference_type n) {
        Iterator temp = it;
        temp += n;
        return temp;
    }
    friend Iterator operator+(difference_type n, const Iterator& it) {
        return it + n;
    }
    friend Iterator operator-(const Iterator& it, difference_type n) {
        Iterator temp = it;
        temp -= n;
        return temp;
    }
    friend difference_type operator-(const Iterator& lhs, const Iterator& rhs) {
        return lhs.m_ptr - rhs.m_ptr;
    }

private:
    T* m_ptr;

};

#endif