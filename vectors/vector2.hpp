#pragma once
#include "../types.hpp"

// TO DO: Write tests

template <typename T>
struct Vector<2, T>
{   
    typedef Vector<2, T> Vector2;
    typedef T value_type;

    // Data
    union{T x, r, s;};
    union{T y, g, t;};
    
    // Element count
    typedef length_t length_type;
    static constexpr length_type length(){return 2};
    
    //-------------------------------------
    // Template method declarations:
    //-------------------------------------

    // Element Access
    constexpr T& operator[](length_type i);
    constexpr T const& operator[](length_type i) const;

    // Implicit basic constructors
    constexpr Vector() = default;
    constexpr Vector(Vector const& v) = default;

    // Explicit basic constructors
    constexpr explicit Vector(T scalar);
    constexpr          Vector(T x, T y);

    // Conversion constructors -- Vector1 --> Vector2
    template <typename U>
    constexpr explicit Vector(Vector<1, U> const& v); 

    // Explicit conversion construtors
    template <typename A, typename B>                                 // Off-type scalars                 
    constexpr Vector(A x, B y);                                       //
    template <typename A, typename B>                                 // Off-type Vector1 and scalar
    constexpr Vector(Vector<1, A> const& x, B y);                     //        "
    template <typename A, typename B>                                 //        "
    constexpr Vector(A x, Vector<1, B> const& y);                     //        "
    template <typename A, typename B>                                 // Two off-type Vector1's
    constexpr Vector(Vector<1, A> const& x, Vector<1, B> const& y);   // 
    
    // Explicit conversion constructors -- VectorN --> Vector2
    template <typename U>
    constexpr explicit Vector(Vector<3, U> const& v);
    template <typename U>
    constexpr explicit Vector(Vector<4, U> const& v);
    template <typename U>
    constexpr explicit Vector(Vector<2, U> const& v);

    // Unary arithmetic operators -- =
    constexpr Vector<2, T> & operator=(Vector const& v) = default;

    template <typename U>
    constexpr Vector<2, T> & operator=(Vector<2, U> const& v);
    
    // Unary arithmetic operator -- +=
    template <typename U>
    constexpr Vector<2, T> & operator+=(U scalar);
    template <typename U>
    constexpr Vector<2, T> & operator+=(Vector<1, U> const& v);
    template <typename U>
    constexpr Vector<2, T> & operator+=(Vector<2, U> const& v);

    // Unary arithmetic operator -- -=
    template <typename U>
    constexpr Vector<2, T> & operator-=(U scalar);
    template <typename U>
    constexpr Vector<2, T> & operator-=(Vector<1, U> const& v);
    template <typename U>
    constexpr Vector<2, T> & operator-=(Vector<2, U> const& v);

    // Unary arithmetic operator -- *=
    template <typename U>
    constexpr Vector<2, T> & operator*=(U scalar);
    template <typename U>
    constexpr Vector<2, T> & operator*=(Vector<1, U> const& v);
    template <typename U>
    constexpr Vector<2, T> & operator*=(Vector<2, U> const& v);

    // Unary arithmetic operator -- /=
    template <typename U>
    constexpr Vector<2, T> & operator/=(U scalar);
    template <typename U>
    constexpr Vector<2, T> & operator/=(Vector<1, U> const& v);
    template <typename U>
    constexpr Vector<2, T> & operator/=(Vector<2, U> const& v);

    // Increment and decrement operators -- prefix
    constexpr Vector<2, T> & operator++();
    constexpr Vector<2, T> & operator--();
    // Increment and decrement operators -- postfix
    constexpr Vector<2, T> & operator++(int);
    constexpr Vector<2, T> & operator--(int);

    // TODO: Unary bitwise operators
    
    void printVectorDetailed()
    {   

        std::cout << "\t     Vector type:\t" << typeid(*this).name() << "\n";
        std::cout << "\tComponent values:\t(" << this->x << ", " << this->y <<")\n";
        std::cout << "\t Component types:\t(" << typeid(this->x).name() << ", " << typeid(this->y).name() << ")" << std::endl; 

        return;
    }
};

// Unary operators
template <typename T>
constexpr Vector<2, T> operator+(Vector<2, T> const& v);
template <typename T>
constexpr Vector<2, T> operator-(Vector<2, T> const& v);

// Binary operators -- +
template <typename T>
constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, T rhs);
template <typename T>
constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, Vector<1, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator+(T lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator+(Vector<1, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator+(Vector<2, T> const& lhs, Vector<2, T> const& rhs);

// Binary operators -- -
template <typename T>
constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, T rhs);
template <typename T>
constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, Vector<1, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator-(T lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator-(Vector<1, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator-(Vector<2, T> const& lhs, Vector<2, T> const& rhs);


// Binary operators -- *
template <typename T>
constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, T rhs);
template <typename T>
constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, Vector<1, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator*(T lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator*(Vector<1, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator*(Vector<2, T> const& lhs, Vector<2, T> const& rhs);

// Binary operators -- /
template <typename T>
constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, T rhs);
template <typename T>
constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, Vector<1, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator/(T lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator/(Vector<1, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator/(Vector<2, T> const& lhs, Vector<2, T> const& rhs);

// Binary operators -- %
template <typename T>
constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, T rhs);
template <typename T>
constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, Vector<1, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator%(T lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator%(Vector<1, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr Vector<2, T> operator%(Vector<2, T> const& lhs, Vector<2, T> const& rhs);

// TODO: Bitwise binary operators

// Boolean operators
template <typename T>
constexpr bool operator==(Vector<2, T> const& lhs, Vector<2, T> const& rhs);
template <typename T>
constexpr bool operator!=(Vector<2, T> const& lhs, Vector<2, T> const& rhs);

constexpr Vector<2, bool> operator&&(Vector<2, bool> const& lhs, Vector<2, bool> const& rhs);

constexpr Vector<2, bool> operator||(Vector<2, bool> const& lhs, Vector<2, bool> const& rhs);

#include "vector2.inl"