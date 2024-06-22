#include "types.hpp"

typedef Vector<2, float> Vector2;
typedef Vector<2, double> dVector2; 
typedef Vector<2, int> iVector2;
typedef Vector<2, unsigned int> uVector2;
typedef Vector<2, bool> bVector2;

template <typename T> 
struct Vector<2, T>
{   
    // Data
    union {T x, r, s;};
    union {T y, g, t;};
    
    // Setup type-agnostic function declarations
    // Element access
    static length length(){return 2;}
    constexpr T& operator[](length i);
    constexpr T const& operator[](length i) const;

    // Constructors -- Implicit
    constexpr Vector() default;
    constexpr Vector(Vector const& v) default;
    constexpr Vector(Vector<2, T> const& v);

    // Constructors -- Explicit
    constexpr explicit Vector(T scalar);
    constexpr Vector(T x, T y);

    // Constructors -- conversion
    template <typename U>
    constexpr explicit Vector(Vector<1, U> const& v);

    // Constructors -- explicit conversion of off-type arguments
    template<typename A, typename B>
    constexpr Vector(A x, B y);

    template<typename A, typename B>
    constexpr Vector(Vector<1, A> const& x, B y);

    template<typename A, typename B>
    constexpr Vector(A x, Vector<1, B> const& y);

    template<typename A, typename B>
    constexpr Vector(Vector<1, A> const&  x, Vector<1, B> const& y);

    // Constructors -- explicit conversion of off-type single vector arguments
    template<typename U>
    constexpr Vector(Vector<3, U> const& v);

    template<typename U>
    constexpr Vector(Vector<4, U> const& v);

    template<typename U>
    constexpr Vector(Vector<2, U> const& v);

    // Swizzle?? TODO?

    // Operator overloading -- off-type
    template<typename U>
    constexpr Vector<2, T>& operator=(Vector<2, U> const& v);
    
    // +=
    template<typename U>
    constexpr Vector<2, T>& operator+=(U scalar);
    template<typename U>
    constexpr Vector<2, T>& operator+=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<2, T>& operator+=(Vector<2, U> const& v);

    // -=
    template<typename U>
    constexpr Vector<2, T>& operator-=(U scalar);
    template<typename U>
    constexpr Vector<2, T>& operator-=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<2, T>& operator-=(Vector<2, U> const& v);

    // *=
    template<typename U>
    constexpr Vector<2, T>& operator*=(U scalar);
    template<typename U>
    constexpr Vector<2, T>& operator*=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<2, T>& operator*=(Vector<2, U> const& v);

    // /=
    template<typename U>
    constexpr Vector<2, T>& operator/=(U scalar);
    template<typename U>
    constexpr Vector<2, T>& operator/=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<2, T>& operator/=(Vector<2, U> const& v);

    // increment and decrement operators
    constexpr Vector<2, T> & operator++();
    constexpr Vector<2, T> & operator--();
    constexpr Vector<2, T> operator++(int);
    constexpr Vector<2, T> operator++(int);

    // unary operators
    template<typename T>
    constexpr Vector<2, T> operator+(Vector<2, T> const& v);
    constexpr Vector<2, T> operator-(Vector<2, T> const& v);

    // binary operators
    // +
    template<typename T>
    constexpr Vector<2, T> operator+(Vector<2, T> const& v, T scalar);
    template<typename T>
    constexpr Vector<2, T> operator+(Vector<2, T> const& v1, Vector<1, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator+(T scalar, Vector<2, T> const& v);
    template<typename T>
    constexpr Vector<2, T> operator+(Vector<1, T> const& v1, Vector<2, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator+(Vector<2, T> const& v1, Vector<2, T> const& v2);

    // -
    template<typename T>
    constexpr Vector<2, T> operator-(Vector<2, T> const& v, T scalar);
    template<typename T>
    constexpr Vector<2, T> operator-(Vector<2, T> const& v1, Vector<1, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator-(T scalar, Vector<2, T> const& v);
    template<typename T>
    constexpr Vector<2, T> operator-(Vector<1, T> const& v1, Vector<2, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator-(Vector<2, T> const& v1, Vector<2, T> const& v2);

    // *
    template<typename T>
    constexpr Vector<2, T> operator*(Vector<2, T> const& v, T scalar);
    template <typename T>
    constexpr Vector<2, T> operator*(Vector<2, T> const& v1, Vector<1, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator*(T scalar, Vector<2, T> const& v);
    template<typename T>
    constexpr Vector<2, T> operator*(Vector<1, T> const& v1, Vector<2, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator*(Vector<2, T> const& v1, Vector<2, T> const& v2);

    // /
    template<typename T>
    constexpr Vector<2, T> operator/(Vector<2, T> const& v, T scalar);
    template <typename T>
    constexpr Vector<2, T> operator/(Vector<2, T> const& v1, Vector<1, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator/(T scalar, Vector<2, T> const& v);
    template<typename T>
    constexpr Vector<2, T> operator/(Vector<1, T> const& v1, Vector<2, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator/(Vector<2, T> const& v1, Vector<2, T> const& v2);

    // %
    template<typename T>
    constexpr Vector<2, T> operator%(Vector<2, T> const& v, T scalar);
    template <typename T>
    constexpr Vector<2, T> operator%(Vector<2, T> const& v1, Vector<1, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator%(T scalar, Vector<2, T> const& v);
    template<typename T>
    constexpr Vector<2, T> operator%(Vector<1, T> const& v1, Vector<2, T> const& v2);
    template<typename T>
    constexpr Vector<2, T> operator%(Vector<2, T> const& v1, Vector<2, T> const& v2);

    // Boolean operators
    template<typename T>
    constexpr bool operator==(Vector<2, T> const& v1, Vector2<2, T> const& v2);
    template<typename T>
    constexpr bool operator!=(Vector<2, T> const& v1, Vector2<2, T> const& v2);
    template<typename T>
    constexpr bool operator&&(Vector<2, T> const& v1, Vector2<2, T> const& v2);
    template<typename T>
    constexpr bool operator||(Vector<2, T> const& v1, Vector2<2, T> const& v2);
};