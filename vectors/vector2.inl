// Implicit basic constructors
template<typename T>
inline constexpr Vector<2, T>::Vector() 
    : x(0), y(0)
{}

template <typename T> 
inline constexpr Vector<2, T>::Vector(Vector<2, T> const& v)
    : x(v.x), y(v.y)
{}

// Explicit basic constructors

template<typename T>
inline constexpr Vector<2, T>::Vector(T scalar)
    : x(scalar), y(scalar)
{}

template<typename T>
inline constexpr Vector<2, T>::Vector(T _x, T _y)
    : x(_x), y(_y)
{}

// Scalar conversion Constructors

template<typename T>
template<typename U>
inline constexpr Vector<2, T>::Vector(Vector<1, U> const& v)
    // initialize both elements of Vector to v.x via a member initializer list
    : x(static_cast<T>(v.x))
    , y(static_cast<T>(v.x)) // static_cast: https://en.cppreference.com/w/cpp/language/static_cast
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
inline constexpr Vector<2, T> & Vector<2, T>::operator=(Vector<2, T> const& v)
{   

    this->x = v.x;
    this->y = v.y;
    return *this;
}

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

// // Unary bit-wise operators:  %= 
// template <typename T>
// template <typename U>
// inline constexpr Vector<2, T> & Vector<2, T>::operator%=(U scalar)
// {   

//     this->x %= static_cast<T>(scalar);
//     this->y %= static_cast<T>(scalar);
//     return *this;
// }
// template <typename T>
// template <typename U>
// inline constexpr Vector<2, T> & Vector<2, T>::operator%=(Vector<1, U> const& v)
// {   

//     this->x %= static_cast<T>(v.x);
//     this->y %= static_cast<T>(v.x);
//     return *this;
// }
// template <typename T>
// template <typename U>
// inline constexpr Vector<2, T> & Vector<2, T>::operator%=(Vector<2, U> const& v)
// {   

//     this->x %= static_cast<T>(v.x);
//     this->y %= static_cast<T>(v.y);
//     return *this;
// }

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
inline constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, T rhs)
{
    return Vector<2, T>(lhs.x + rhs,
                        lhs.y + rhs);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, Vector<1, T> const& rhs)
{
    return Vector<2, T>(lhs.x + rhs.x,
                        lhs.y + rhs.x);
}
template<typename T>
inline constexpr Vector<2, T> operator+(T lhs, Vector<2, T> const& v)
{
    return Vector<2, T>(lhs + v.x, 
                        lhs + v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<1, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x + rhs.x,
                        lhs.x + rhs.y);
}
template<typename T>
inline constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x + rhs.x,
                        lhs.y + rhs.y);
}

// Binary operators:    -
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, T rhs)
{
    return Vector<2, T>(lhs.x - rhs,
                        lhs.y - rhs);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, Vector<1, T> const& rhs)
{
    return Vector<2, T>(lhs.x - rhs.x,
                        lhs.y - rhs.x);
}
template<typename T>
inline constexpr Vector<2, T> operator-(T lhs, Vector<2, T> const& v)
{
    return Vector<2, T>(lhs - v.x, 
                        lhs - v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<1, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x - rhs.x,
                        lhs.x - rhs.y);
}
template<typename T>
inline constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x - rhs.x,
                        lhs.y - rhs.y);
}

// Binary operators:    *
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, T rhs)
{
    return Vector<2, T>(lhs.x * rhs,
                        lhs.y * rhs);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, Vector<1, T> const& rhs)
{
    return Vector<2, T>(lhs.x * rhs.x,
                        lhs.y * rhs.x);
}
template<typename T>
inline constexpr Vector<2, T> operator*(T lhs, Vector<2, T> const& v)
{
    return Vector<2, T>(lhs * v.x, 
                        lhs * v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<1, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x * rhs.x,
                        lhs.x * rhs.y);
}
template<typename T>
inline constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x * rhs.x,
                        lhs.y * rhs.y);
}

// Binary operators:    /
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, T rhs)
{
    return Vector<2, T>(lhs.x / rhs,
                        lhs.y / rhs);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, Vector<1, T> const& rhs)
{
    return Vector<2, T>(lhs.x / rhs.x,
                        lhs.y / rhs.x);
}
template<typename T>
inline constexpr Vector<2, T> operator/(T lhs, Vector<2, T> const& v)
{
    return Vector<2, T>(lhs / v.x, 
                        lhs / v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<1, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x / rhs.x,
                        lhs.x / rhs.y);
}
template<typename T>
inline constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x / rhs.x,
                        lhs.y / rhs.y);
}

// Binary operators:    %
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, T rhs)
{
    return Vector<2, T>(lhs.x % rhs,
                        lhs.y % rhs);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, Vector<1, T> const& rhs)
{
    return Vector<2, T>(lhs.x % rhs.x,
                        lhs.y % rhs.x);
}
template<typename T>
inline constexpr Vector<2, T> operator%(T lhs, Vector<2, T> const& v)
{
    return Vector<2, T>(lhs % v.x, 
                        lhs % v.y);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<1, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x % rhs.x,
                        lhs.x % rhs.y);
}
template<typename T>
inline constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x % rhs.x,
                        lhs.y % rhs.y);
}

// TODO: create common computation header file a la compute_common.hpp and compute_vector_relational.hpp
//       in order to have proper and portable floating point comparissons

#include <limits>

template <typename T>
constexpr bool isEqual(T lhs, T rhs)
{
    if (std::numeric_limits<T>::is_iec559) // is type T a floating point type?
    {   
        T min = (fabs(lhs) > fabs(rhs) ? fabs(rhs) : fabs(lhs));
        return (fabs(lhs - rhs) <= min * std::numeric_limits<T>::epsilon());
    } 
    else { return lhs == rhs;}
}

// Boolean operators
template<typename T>
inline constexpr bool operator==(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{   

        return (isEqual(lhs.x, rhs.x) && isEqual(lhs.y, rhs.y));
}
template<typename T>
inline constexpr bool operator!=(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return !(lhs == rhs);
}
template<typename T>
inline constexpr Vector<2, bool> operator&&(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{   
    return Vector<2, bool>(lhs.x && rhs.x, lhs.y && rhs.y);
}
template<typename T>
inline constexpr Vector<2, bool> operator||(Vector<2, T> const& lhs, Vector<2, T> const& rhs)
{
    return Vector<2, T>(lhs.x || rhs.x, lhs.y || rhs.y);
}