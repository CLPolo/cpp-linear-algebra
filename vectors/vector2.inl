#include "vector2.hpp"

// Constructors -- Basic
template<typename T>
inline constexpr Vector<2, T>::Vector() 
    : x(0), y(0)
{}

template <typename T> 
inline constexpr Vector<2, T>::Vector(Vector<2, T> const& v)
    : x(v.x), y(v.y)
{}

template<typename T>
inline constexpr Vector<2, T>::Vector(T scalar)
    : x(scalar), y(scalar)
{}

template<typename T>
inline constexpr Vector<2, T>::Vector(T _x, T _y)
    : x(_x), y(_y)
{}

// Constructors -- Scalar conversion 
// static_cast: https://en.cppreference.com/w/cpp/language/static_cast
template<typename T>
template<typename U>
inline constexpr Vector<2, T>::Vector(Vector<1, U> const& v)
    // initialize both elements of Vector to v.x via a member initializer list
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.x))
{}

template<typename T>
template<typename A, typename B>
inline constexpr Vector<2, T>::Vector(A _x, B _y)
    : x(static_cast<T>(_x))
    , y(static_cast<T>(_y))
{}

template<typename T>
template<typename A, typename B>
inline constexpr Vector<2, T>::Vector(Vector<1, A> const& _x, B _y)
    : x(static_cast<T>(_x.x))
    , y(static_cast<T>(y))
{}

template<typename T>
template<typename A, typename B>
inline constexpr Vector<2, T>::Vector(A _x, Vector<1, B> const& _y)
    : x(static_cast<T>(_x))
    , y(static_cast<T>(_y.x))
{}

template<typename T>
template<typename A, typename B>
inline constexpr Vector<2, T>::Vector(Vector<1, A> const& _x, Vector<1, B> const& _y)
    : x(static_cast<T>(_x.x))
    , y(static_cast<T>(_y.x))
{}

// Vector conversion constructors

template<typename T>
template<typename U>
inline constexpr Vector<2, T>::Vector(Vector<2, U> const& v)
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.y))
{}

template<typename T>
template<typename U>
inline constexpr Vector<2, T>::Vector(Vector<3, U> const& v)
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.y))
{}

template<typename T>
template<typename U>
inline constexpr Vector<2, T>::Vector(Vector<4, U> const& v)
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.y))
{}

// Element access
template<typename T>  
inline constexpr T & Vector<2, T>::operator[](typename Vector<2, T>::length_type i)
{   
    // validate i 
    ASSERT_LENGTH(i, this->length());
    switch (i):
    {
        case 0:
            return x;
        case 1:
            return y;
    }
}

template<typename T>  
inline constexpr T const& Vector<2, T>::operator[](typename Vector<2, T>::length_type i) const
{   
    // validate i 
    ASSERT_LENGTH(i, this->length());
    switch (i):
    {
        case 0:
            return x;
        case 1:
            return y;
    }
}

// Unary arithmetic operators:  =
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator=(Vector<2, U> const& v)
{   

    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    return *this;
}


// Unary arithmetic operators:  += 
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator+=(U scalar)
{   

    this->x += static_cast<T>(scalar);
    this->y += static_cast<T>(scalar);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator+=(Vector<1, U> const& v)
{   

    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.x);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator+=(Vector<2, U> const& v)
{   

    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    return *this;
}

// Unary arithmetic operators:  -= 
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator-=(U scalar)
{   

    this->x -= static_cast<T>(scalar);
    this->y -= static_cast<T>(scalar);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator-=(Vector<1, U> const& v)
{   

    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.x);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator-=(Vector<2, U> const& v)
{   

    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    return *this;
}

// Unary arithmetic operators:   *= 
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator*=(U scalar)
{   

    this->x *= static_cast<T>(scalar);
    this->y *= static_cast<T>(scalar);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator*=(Vector<1, U> const& v)
{   

    this->x *= static_cast<T>(v.x);
    this->y *= static_cast<T>(v.x);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator*=(Vector<2, U> const& v)
{   

    this->x *= static_cast<T>(v.x);
    this->y *= static_cast<T>(v.y);
    return *this;
}

// Unary arithmetic operators:  /= 
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator/=(U scalar)
{   

    this->x /= static_cast<T>(scalar);
    this->y /= static_cast<T>(scalar);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator/=(Vector<1, U> const& v)
{   

    this->x /= static_cast<T>(v.x);
    this->y /= static_cast<T>(v.x);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator/=(Vector<2, U> const& v)
{   

    this->x /= static_cast<T>(v.x);
    this->y /= static_cast<T>(v.y);
    return *this;
}

// Increment and decrement operators -- prefix
template<typename T>
inline constexpr Vector<2, T> & Vector<2, T>::operator++()
{
    ++this->x;
    ++this->y;
    return *this;
}
template<typename T>
inline constexpr Vector<2, T> & Vector<2, T>::operator--()
{
    --this->x;
    --this->y;
    return *this;
}

// Increment and decrement operators -- postfix
template<typename T>
inline constexpr Vector<2, T> & Vector<2, T>::operator++(int)
{
    Vector<2, T> result(*this); // copy prior to increment
    ++(*this);                  // apply increment to original
    return result;              // return copy
}
template<typename T>
inline constexpr Vector<2, T> & Vector<2, T>::operator--(int)
{
    Vector<2, T> result(*this);
    --(*this);
    return result;
}

// Unary bit-wise operators:  %= 
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator%=(U scalar)
{   

    this->x %= static_cast<T>(scalar);
    this->y %= static_cast<T>(scalar);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator%=(Vector<1, U> const& v)
{   

    this->x %= static_cast<T>(v.x);
    this->y %= static_cast<T>(v.x);
    return *this;
}
template <typename T>
template <typename U>
inline constexpr Vector<2, T> & Vector<2, T>::operator%=(Vector<2, U> const& v)
{   

    this->x %= static_cast<T>(v.x);
    this->y %= static_cast<T>(v.y);
    return *this;
}

// Unary operators
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& v)
{
    return v;
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& v)
{
    return Vector<2, T>(-v.x, -v.y);
}

// Binary operators:    +
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& v, T scalar)
{
    return Vector<2, T>(v.x + scalar
                        v.y + scalar);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& v1, Vector<1, T> const& v2)
{
    return Vector<2, T>(v1.x + v2.x
                        v1.y + v2.x);
}
template<typename T>
inline constexpr Vector<2, T> operator+(T scalar, Vector<2, T> const& v)
{
    return Vector<2, T>(scalar + v.x, 
                        scalar + v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<1, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x + v2.x
                        v1.x + v2.y);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x + v2.y
                        v1.y + v2.y);
}

// Binary operators:    -
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& v, T scalar)
{
    return Vector<2, T>(v.x - scalar
                        v.y - scalar);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& v1, Vector<1, T> const& v2)
{
    return Vector<2, T>(v1.x - v2.x
                        v1.y - v2.x);
}
template<typename T>
inline constexpr Vector<2, T> operator-(T scalar, Vector<2, T> const& v)
{
    return Vector<2, T>(scalar - v.x, 
                        scalar - v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<1, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x - v2.x
                        v1.x - v2.y);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x - v2.y
                        v1.y - v2.y);
}

// Binary operators:    *
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& v, T scalar)
{
    return Vector<2, T>(v.x * scalar
                        v.y * scalar);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& v1, Vector<1, T> const& v2)
{
    return Vector<2, T>(v1.x * v2.x
                        v1.y * v2.x);
}
template<typename T>
inline constexpr Vector<2, T> operator*(T scalar, Vector<2, T> const& v)
{
    return Vector<2, T>(scalar * v.x, 
                        scalar * v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<1, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x * v2.x
                        v1.x * v2.y);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x * v2.y
                        v1.y * v2.y);
}

// Binary operators:    /
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& v, T scalar)
{
    return Vector<2, T>(v.x / scalar
                        v.y / scalar);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& v1, Vector<1, T> const& v2)
{
    return Vector<2, T>(v1.x / v2.x
                        v1.y / v2.x);
}
template<typename T>
inline constexpr Vector<2, T> operator/(T scalar, Vector<2, T> const& v)
{
    return Vector<2, T>(scalar / v.x, 
                        scalar / v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<1, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x / v2.x
                        v1.x / v2.y);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x / v2.y
                        v1.y / v2.y);
}

// Binary operators:    %
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& v, T scalar)
{
    return Vector<2, T>(v.x % scalar
                        v.y % scalar);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& v1, Vector<1, T> const& v2)
{
    return Vector<2, T>(v1.x % v2.x
                        v1.y % v2.x);
}
template<typename T>
inline constexpr Vector<2, T> operator%(T scalar, Vector<2, T> const& v)
{
    return Vector<2, T>(scalar % v.x, 
                        scalar % v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<1, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x % v2.x
                        v1.x % v2.y);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x % v2.y
                        v1.y % v2.y);
}

// Boolean operators
template<typename T>
inline constexpr bool operator==(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}
template<typename T>
inline constexpr bool operator!=(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return !(v1 == v2);
}
template<typename T>
inline constexpr Vector<2, bool> operator&&(Vector<2, T> const& v1, Vector<2, T> const& v2)
{   
    return Vector<2, bool>(v1.x && v2.x, v1.y && v2.y);
}
template<typename T>
inline constexpr Vector<2, bool> operator||(Vector<2, T> const& v1, Vector<2, T> const& v2)
{
    return Vector<2, T>(v1.x || v2.x, v1.y || v2.y);
}