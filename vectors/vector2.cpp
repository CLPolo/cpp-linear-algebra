#include "vector2.hpp"

// Constructors -- Basic
template <typename T>
constexpr Vector<2, T>::Vector(Vector<2, T> const& v)
    : x(v.x), y(v.y)
{}

template<typename T>
constexpr Vector<2, T>::Vector(T scalar)
    : x(scalar), y(scalar)
{}

template<typename T>
constexpr Vector<2, T>::Vector(T _x, T _y)
    : x(_x), y(_y)
{}

// Constructors -- Scalar conversion
template<typename T>
template<typename U>
constexpr Vector<2, T>::Vector(Vector<1, U> const& v)
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.x))
{}

template<typename T>
template<typename A, typename B>
constexpr Vector<2, T>::Vector(A _x, B _y)
    : x(static_cast<T>(_x))
    , y(static_cast<T>(_y))
{}