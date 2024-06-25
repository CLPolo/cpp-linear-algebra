#include "../types.hpp"

template <typename T> 
struct Vector<2, T>
{   
    typedef T value_type;
    typedef Vector<2, T> type;
    typedef Vector<2, bool> bool_type;

    // Data
    union {T x, r, s;};
    union {T y, g, t;};
    
    // Setup type-agnostic function declarations
    
    // Get element count
    typedef length_t length_type;
    static constexpr length_type length(){return 2;}
    
    // Element access
    constexpr T& operator[](length_type i);
    constexpr T const& operator[](length_type i) const;

    // Constructors -- Implicit
    constexpr Vector() = default;                // default constructor: https://en.cppreference.com/w/cpp/language/default_constructor
    constexpr Vector(Vector const& v) = default; // copy constructor: https://en.cppreference.com/w/cpp/language/copy_constructor
    constexpr Vector(Vector<2, T> const& v);

    // Constructors -- Explicit
    constexpr explicit Vector(T scalar);
    constexpr Vector(T x, T y);

    // Constructors -- conversion -- https://en.cppreference.com/w/cpp/language/converting_constructor
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
    constexpr Vector(Vector<2, U> const& v);

    template<typename U>
    constexpr Vector(Vector<3, U> const& v);

    template<typename U>
    constexpr Vector(Vector<4, U> const& v);

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