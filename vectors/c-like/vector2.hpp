#include <cassert>
#define ASSERT_LENGTH(l, max) (assert ((l) >= 0 && (l) < (max)))
namespace linalg
{
typedef struct Vector
{   
    // Data
    typedef int length_t;
    const length_t length = 2;
    union{float x, r, s;};
    union{float y, g, t;};

    //Constructors -- basic
    constexpr Vector()
        : x(0.0f), y(0.0f)
    {}   

    constexpr Vector(Vector const& v)
        : x(v.x), y(v.x)
    {   
        if (v.length > 1) y = v.y;         
    }

    template<typename T>
    constexpr Vector(T scalar)
        : x((float)scalar)
        , y((float)scalar)
    {}

    template<typename T>
    constexpr Vector(T _x, T _y)
        : x((float)_x)
        , y((float)_y)
    {}

    // Constructors -- scalar conversion
    template<typename T, typename U>
    constexpr Vector(T _x, U _y)
        : x((float)_x)
        , y((float)_y)
    {}

    template<typename T>
    constexpr Vector(Vector _x, T _y)
        : x((float)x.x)
        , y((float)_y)
    {}

    template<typename T>
    constexpr Vector(T _x, Vector _y)
        : x((float)_x)
        , y((float)_y.x)
    {
        if (_y.length > 1) y = (float)_y.y;
    }

    // Component access
    constexpr float& Vector2::operator[](length_t i)
    {
        ASSERT_LENGTH(i, length);
        switch (i)
        {
            case 0:
                return x;
            case 1:
                return y;
        }

    }

    constexpr float const& Vector2::operator[](length_t i) const
    {
        ASSERT_LENGTH(i, length);
        switch (i)
        {
            case 0:
                return x;
            case 1:
                return y;
        }

    }

    // Unary arithmetic operators:  =
    constexpr Vector2 & Vector2::operator=(Vector const& v)
    {
        this->x = (float)v.x;
        this->y = (float)v.y;
    }

    // Unary arithmetic operators:  +=
    template <typename T>
    constexpr Vector2 & Vector2::operator+=(T scalar)
    {
        this->x += (float)scalar;
        this->y += (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator+=(Vector const& v)
    {
        this->x += (float)v.x;
        
        if (v.length > 1)
        {
            this->y += (float)v.y;
        } else {
            this->y += (float)v.x;
        }
    }

    // Unary arithmetic operators:  -=
    template <typename T>
    constexpr Vector2 & Vector2::operator-=(T scalar)
    {
        this->x -= (float)scalar;
        this->y -= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator-=(Vector const& v)
    {
        this->x -= (float)v.x;
        
        if (v.length > 1)
        {
            this->y -= (float)v.y;
        } else {
            this->y -= (float)v.x;
        }
    }

    // Unary arithmetic operators:  *=
    template <typename T>
    constexpr Vector2 & Vector2::operator*=(T scalar)
    {
        this->x *= (float)scalar;
        this->y *= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator*=(Vector const& v)
    {
        this->x *= (float)v.x;
        
        if (v.length > 1)
        {
            this->y *= (float)v.y;
        } else {
            this->y *= (float)v.x;
        }
    }

    // Unary arithmetic operators:  /=
    template <typename T>
    constexpr Vector2 & Vector2::operator/=(T scalar)
    {
        this->x /= (float)scalar;
        this->y /= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator/=(Vector const& v)
    {
        this->x /= (float)v.x;
        
        if (v.length > 1)
        {
            this->y /= (float)v.y;
        } else {
            this->y /= (float)v.x;
        }
    }

    // Increment and decrement operators -- prefix
    constexpr Vector2 & Vector2::operator++()
    {
        ++(this->x);
        ++(this->y);
        return *this;
    }
    constexpr Vector2 & Vector2::operator--()
    {
        --(this->x);
        --(this->y);
        return *this;
    }

    // Increment and decrement operators -- postfix
    constexpr Vector2 & Vector2::operator++(int)
    {
        Vector2 result(*this);  // copy prior to increment
        ++(*this);              // apply increment to original
        return result;          // return copy       
    }
    constexpr Vector2 & Vector2::operator--(int)
    {
        Vector2 result(*this);  // copy prior to decrement
        --(*this);              // apply increment to original
        return result;          // return copy       
    }

    // Unary bit-wise operators:  %= (modulus)
    template <typename T>
    constexpr Vector2 & Vector2::operator%=(T scalar)
    {
        this->x %= (float)scalar;
        this->y %= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator%=(Vector const& v)
    {
        this->x %= (float)v.x;
        
        if (v.length > 1)
        {
            this->y %= (float)v.y;
        } else {
            this->y %= (float)v.x;
        }
    }

    // Unary bit-wise operators:  &= (bit-wise and)
    template <typename T>
    constexpr Vector2 & Vector2::operator&=(T scalar)
    {
        this->x &= (float)scalar;
        this->y &= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator&=(Vector const& v)
    {
        this->x &= (float)v.x;
        
        if (v.length > 1)
        {
            this->y &= (float)v.y;
        } else {
            this->y &= (float)v.x;
        }
    }

    // Unary bit-wise operators:  |= (bit-wise or)
    template <typename T>
    constexpr Vector2 & Vector2::operator|=(T scalar)
    {
        this->x |= (float)scalar;
        this->y |= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator|=(Vector const& v)
    {
        this->x |= (float)v.x;
        
        if (v.length > 1)
        {
            this->y |= (float)v.y;
        } else {
            this->y |= (float)v.x;
        }
    }

    // Unary bit-wise operators:  ^= (bit-wise xor)
    template <typename T>
    constexpr Vector2 & Vector2::operator^=(T scalar)
    {
        this->x ^= (float)scalar;
        this->y ^= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator^=(Vector const& v)
    {
        this->x ^= (float)v.x;
        
        if (v.length > 1)
        {
            this->y ^= (float)v.y;
        } else {
            this->y ^= (float)v.x;
        }
    }

    // Unary bit-wise operators:  <<= (bit-wise shift left)
    template <typename T>
    constexpr Vector2 & Vector2::operator<<=(T scalar)
    {
        this->x <<= (float)scalar;
        this->y <<= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator<<=(Vector const& v)
    {
        this->x <<= (float)v.x;
        
        if (v.length > 1)
        {
            this->y <<= (float)v.y;
        } else {
            this->y <<= (float)v.x;
        }
    }

    // Unary bit-wise operators:  >>= (bit-wise shift right)
    template <typename T>
    constexpr Vector2 & Vector2::operator>>=(T scalar)
    {
        this->x >>= (float)scalar;
        this->y >>= (float)scalar;
    }
    template <typename T>
    constexpr Vector2 & Vector2::operator>>=(Vector const& v)
    {
        this->x >>= (float)v.x;
        
        if (v.length > 1)
        {
            this->y >>= (float)v.y;
        } else {
            this->y >>= (float)v.x;
        }
    }
} Vector2;

// Unary operators
inline constexpr Vector2 operator+(Vector2 const& v)
{
    return v;
}
constexpr Vector2 operator-(Vector2 const&v)
{
    return Vector(-v.x,-v.y);
}
// Binary Operators:    +
template <typename T>
inline constexpr Vector2 operator+(Vector2 const& v, T scalar)
{
    return Vector(v.x + scalar,
                  v.y + scalar);
}
template <typename T>
inline constexpr Vector2 operator+(T scalar, Vector2 const& v)
{
    return Vector(scalar + v.x,
                  scalar + v.y);
}
inline constexpr Vector2 operator+(Vector2 const& v1, Vector v2)
{
    if (v2.length > 1)
    {
        return Vector(v1.x + v2.x,
                      v1.y + v2.y);
    } 
    else 
    {
        return Vector(v1.x + v2.x,
                      v1.y + v2.x);
    }
}
inline constexpr Vector2 operator+(Vector v1, Vector2 const& v2)
{
    if (v1.length > 1)
    {
        return Vector(v1.x + v2.x,
                      v1.y + v2.y);
    } 
    else 
    {
        return Vector(v1.x + v2.x,
                      v1.x + v2.y);
    }
}

// Binary Operators:    -
template <typename T>
inline constexpr Vector2 operator-(Vector2 const& v, T scalar)
{
    return Vector(v.x - scalar,
                  v.y - scalar);
}
template <typename T>
inline constexpr Vector2 operator-(T scalar, Vector2 const& v)
{
    return Vector(scalar - v.x,
                  scalar - v.y);
}
inline constexpr Vector2 operator-(Vector2 const& v1, Vector v2)
{
    if (v2.length > 1)
    {
        return Vector(v1.x - v2.x,
                      v1.y - v2.y);
    } 
    else 
    {
        return Vector(v1.x - v2.x,
                      v1.y - v2.x);
    }
}
inline constexpr Vector2 operator-(Vector v1, Vector2 const& v2)
{
    if (v1.length > 1)
    {
        return Vector(v1.x - v2.x,
                      v1.y - v2.y);
    } 
    else 
    {
        return Vector(v1.x - v2.x,
                      v1.x - v2.y);
    }
}

// Binary Operators:    *
template <typename T>
inline constexpr Vector2 operator*(Vector2 const& v, T scalar)
{
    return Vector(v.x * scalar,
                  v.y * scalar);
}
template <typename T>
inline constexpr Vector2 operator*(T scalar, Vector2 const& v)
{
    return Vector(scalar * v.x,
                  scalar * v.y);
}
inline constexpr Vector2 operator*(Vector2 const& v1, Vector v2)
{
    if (v2.length > 1)
    {
        return Vector(v1.x * v2.x,
                      v1.y * v2.y);
    } 
    else 
    {
        return Vector(v1.x * v2.x,
                      v1.y * v2.x);
    }
}
inline constexpr Vector2 operator*(Vector v1, Vector2 const& v2)
{
    if (v1.length > 1)
    {
        return Vector(v1.x * v2.x,
                      v1.y * v2.y);
    } 
    else 
    {
        return Vector(v1.x * v2.x,
                      v1.x * v2.y);
    }
}

// Binary Operators:    /
template <typename T>
inline constexpr Vector2 operator/(Vector2 const& v, T scalar)
{
    return Vector(v.x / (float)scalar,
                  v.y / (float)scalar);
}
template <typename T>
inline constexpr Vector2 operator/(T scalar, Vector2 const& v)
{
    return Vector((float)scalar / v.x,
                  (float)scalar / v.y);
}
inline constexpr Vector2 operator/(Vector2 const& v1, Vector v2)
{
    if (v2.length > 1)
    {
        return Vector(v1.x / (float)v2.x,
                      v1.y / (float)v2.y);
    } 
    else 
    {
        return Vector(v1.x / (float)v2.x,
                      v1.y / (float)v2.x);
    }
}
inline constexpr Vector2 operator/(Vector v1, Vector2 const& v2)
{
    if (v1.length > 1)
    {
        return Vector(v1.x / v2.x,
                      v1.y / v2.y);
    } 
    else 
    {
        return Vector(v1.x / v2.x,
                      v1.x / v2.y);
    }
}

// Boolean Operators
inline constexpr bool operator==(Vector2 v1, Vector2 v2)
{
    return (v1.x == v2.x, v1.y == v2.y);
}
inline constexpr bool operator!=(Vector2 v1, Vector2 v2)
{
    return !(v1 == v2);
}

// Binary bit operators -- to be implemented properly

// // Binary bit Operators:    %
// template <typename T>
// inline constexpr Vector2 operator%(Vector2 const& v, T scalar)
// {
//     return Vector(v.x % scalar,
//                   v.y % scalar);
// }
// template <typename T>
// inline constexpr Vector2 operator%(T scalar, Vector2 const& v)
// {
//     return Vector(scalar % v.x,
//                   scalar % v.y);
// }
// inline constexpr Vector2 operator%(Vector2 const& v1, Vector v2)
// {
//     if (v2.length > 1)
//     {
//         return Vector(v1.x % v2.x,
//                       v1.y % v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x % v2.x,
//                       v1.y % v2.x);
//     }
// }
// inline constexpr Vector2 operator%(Vector v1, Vector2 const& v2)
// {
//     if (v1.length > 1)
//     {
//         return Vector(v1.x % v2.x,
//                       v1.y % v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x % v2.x,
//                       v1.x % v2.y);
//     }
// }

// // Binary bit Operators:    &
// template <typename T>
// inline constexpr Vector2 operator&(Vector2 const& v, T scalar)
// {
//     return Vector(v.x & scalar,
//                   v.y & scalar);
// }
// template <typename T>
// inline constexpr Vector2 operator&(T scalar, Vector2 const& v)
// {
//     return Vector(scalar & v.x,
//                   scalar & v.y);
// }
// inline constexpr Vector2 operator&(Vector2 const& v1, Vector v2)
// {
//     if (v2.length > 1)
//     {
//         return Vector(v1.x & v2.x,
//                       v1.y & v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x & v2.x,
//                       v1.y & v2.x);
//     }
// }
// inline constexpr Vector2 operator&(Vector v1, Vector2 const& v2)
// {
//     if (v1.length > 1)
//     {
//         return Vector(v1.x & v2.x,
//                       v1.y & v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x & v2.x,
//                       v1.x & v2.y);
//     }
// }

// // Binary bit Operators:    |
// template <typename T>
// inline constexpr Vector2 operator|(Vector2 const& v, T scalar)
// {
//     return Vector(v.x | scalar,
//                   v.y | scalar);
// }
// template <typename T>
// inline constexpr Vector2 operator|(T scalar, Vector2 const& v)
// {
//     return Vector(scalar | v.x,
//                   scalar | v.y);
// }
// inline constexpr Vector2 operator|(Vector2 const& v1, Vector v2)
// {
//     if (v2.length > 1)
//     {
//         return Vector(v1.x | v2.x,
//                       v1.y | v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x | v2.x,
//                       v1.y | v2.x);
//     }
// }
// inline constexpr Vector2 operator|(Vector v1, Vector2 const& v2)
// {
//     if (v1.length > 1)
//     {
//         return Vector(v1.x | v2.x,
//                       v1.y | v2.y);
//     } 
//     else 
//     {
//         return Vector(v1.x | v2.x,
//                       v1.x | v2.y);
//     }
// }