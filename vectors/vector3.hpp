#include "../types.hpp"

template <typename T> 
struct Vector<3, T>
{   
    typedef T value_type;
    typedef Vector<3, T> type;
    typedef Vector<3, bool> bool_type;

    // Data
    union {T x, r, s;};
    union {T y, g, t;};
    union {T z, b, p;};
    
    // Setup type-agnostic function declarations
    
    // Get element count
    typedef length_t length_type;
    static constexpr length_type length(){return 3;}
    
    // Element access
    constexpr T& operator[](length_type i);
    constexpr T const& operator[](length_type i) const;

    // Constructors -- Implicit
    constexpr Vector() = default;             // default constructor: https://en.cppreference.com/w/cpp/language/default_constructor
    constexpr Vector(Vector const& v) = default; // copy constructor: https://en.cppreference.com/w/cpp/language/copy_constructor
    constexpr Vector(Vector<3, T> const& v);

    // Constructors -- Explicit
    constexpr explicit Vector(T scalar);
    constexpr Vector(T x, T y, T z);

    // Constructors -- conversion -- https://en.cppreference.com/w/cpp/language/converting_constructor
    template <typename U>
    constexpr explicit Vector(Vector<1, U> const& v);

    // Constructors -- explicit conversion
    template<typename X, typename Y, typename Z>
    constexpr Vector(X x, Y y, Z z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(Vector<1, X> const& _x, Y _y, Z _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(X _x, Vector<1, Y> const& _y, Z _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(Vector<1, X> const& _x, Vector<1, Y> const& _y, Z _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(X _x, Y _y, Vector<1, Z> const& _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(Vector<1, X> const& _x, Y _y, Vector<1, Z> const& _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(X _x, Vector<1, Y> const& _y, Vector<1, Z> const& _z);

    template<typename X, typename Y, typename Z>
    constexpr Vector(Vector<1, X> const& _x, Vector<1, Y> const& _y, Vector<1, Z> const& _z);

    template<typename A, typename B>
    constexpr Vector(Vector<2, A> const& _xy, B _z);

    template<typename A, typename B>
    constexpr Vector(Vector<2, A> const& _xy, Vector<1, B> const& _z);

    template<typename A, typename B>
    constexpr Vector(A _x, Vector<2, B> const& _yz);

    template<typename A, typename B>
    constexpr Vector(Vector<1, A> const& _x, Vector<2, B> const& _yz);

    template<typename U>
    constexpr explicit Vector(Vector<4, U> const& v);

    template<typename U>
    constexpr explicit Vector(Vector<3, U> const& v);
    
    // Swizzle?? TODO?
	
	// Unary arithmetic operators:  =
    constexpr Vector<3, T>& operator=(Vector<3, T> const& v) GLM_DEFAULT;
    template<typename U>
    constexpr Vector<3, T> & operator=(Vector<3, U> const& v);
    
    // Unary arithmetic operators:  +=
    template<typename U>
    constexpr Vector<3, T> & operator+=(U scalar);
    template<typename U>
    constexpr Vector<3, T> & operator+=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<3, T> & operator+=(Vector<3, U> const& v);
    template<typename U>
    
    // Unary arithmetic operators:  -=
    constexpr Vector<3, T> & operator-=(U scalar);
    template<typename U>
    constexpr Vector<3, T> & operator-=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<3, T> & operator-=(Vector<3, U> const& v);
    template<typename U>
    
    // Unary arithmetic operators:  *=
    constexpr Vector<3, T> & operator*=(U scalar);
    template<typename U>
    constexpr Vector<3, T> & operator*=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<3, T> & operator*=(Vector<3, U> const& v);
    template<typename U>
    
    // Unary arithmetic operators:  /=
    constexpr Vector<3, T> & operator/=(U scalar);
    template<typename U>
    constexpr Vector<3, T> & operator/=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<3, T> & operator/=(Vector<3, U> const& v);

    // Unary arithmetic operators:  %=
    template<typename U>
    constexpr Vector<3, T> & operator%=(U scalar);
    template<typename U>
    constexpr Vector<3, T> & operator%=(Vector<1, U> const& v);
    template<typename U>
    constexpr Vector<3, T> & operator%=(Vector<3, U> const& v);

    // Increment and decrement operators
    constexpr Vector<3, T> & operator++();
    constexpr Vector<3, T> & operator--();
    constexpr Vector<3, T> operator++(int);
    constexpr Vector<3, T> operator--(int);

    // Unary arithmetic bit-wise operators -- omitting for now
    // template<typename U>
    // constexpr Vector<3, T> & operator&=(U scalar);
    // template<typename U>
    // constexpr Vector<3, T> & operator&=(Vector<1, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator&=(Vector<3, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator|=(U scalar);
    // template<typename U>
    // constexpr Vector<3, T> & operator|=(Vector<1, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator|=(Vector<3, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator^=(U scalar);
    // template<typename U>
    // constexpr Vector<3, T> & operator^=(Vector<1, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator^=(Vector<3, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator<<=(U scalar);
    // template<typename U>
    // constexpr Vector<3, T> & operator<<=(Vector<1, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator<<=(Vector<3, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator>>=(U scalar);
    // template<typename U>
    // constexpr Vector<3, T> & operator>>=(Vector<1, U> const& v);
    // template<typename U>
    // constexpr Vector<3, T> & operator>>=(Vector<3, U> const& v);
};

    // Unary operators --
	template<typename T>
	constexpr Vector<3, T> operator+(Vector<3, T> const& v);

	template<typename T>
	constexpr Vector<3, T> operator-(Vector<3, T> const& v);

	// Binary operators:     +
	template<typename T>
	constexpr Vector<3, T> operator+(Vector<3, T> const& v, T scalar);
	template<typename T>
	constexpr Vector<3, T> operator+(Vector<3, T> const& v, Vector<1, T> const& scalar);
	template<typename T>
	constexpr Vector<3, T> operator+(T scalar, Vector<3, T> const& v);
	template<typename T>
	constexpr Vector<3, T> operator+(Vector<1, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator+(Vector<3, T> const& v1, Vector<3, T> const& v2);

    // Binary operators:     -
	template<typename T>
	constexpr Vector<3, T> operator-(Vector<3, T> const& v, T scalar);
	template<typename T>
	constexpr Vector<3, T> operator-(Vector<3, T> const& v1, Vector<1, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator-(T scalar, Vector<3, T> const& v);
	template<typename T>
	constexpr Vector<3, T> operator-(Vector<1, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator-(Vector<3, T> const& v1, Vector<3, T> const& v2);

    // Binary operators:     *
	template<typename T>
	constexpr Vector<3, T> operator*(Vector<3, T> const& v, T scalar);
	template<typename T>
	constexpr Vector<3, T> operator*(Vector<3, T> const& v1, Vector<1, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator*(T scalar, Vector<3, T> const& v);
	template<typename T>
	constexpr Vector<3, T> operator*(Vector<1, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator*(Vector<3, T> const& v1, Vector<3, T> const& v2);

    // Binary operators:     /
	template<typename T>
	constexpr Vector<3, T> operator/(Vector<3, T> const& v, T scalar);
	template<typename T>
	constexpr Vector<3, T> operator/(Vector<3, T> const& v1, Vector<1, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator/(T scalar, Vector<3, T> const& v);
	template<typename T>
	constexpr Vector<3, T> operator/(Vector<1, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator/(Vector<3, T> const& v1, Vector<3, T> const& v2);

    // Binary operators:     %
	template<typename T>
	constexpr Vector<3, T> operator%(Vector<3, T> const& v, T scalar);
	template<typename T>
	constexpr Vector<3, T> operator%(Vector<3, T> const& v1, Vector<1, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator%(T scalar, Vector<3, T> const& v);
	template<typename T>
	constexpr Vector<3, T> operator%(Vector<1, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr Vector<3, T> operator%(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// Boolean operators 
	template<typename T>
	constexpr bool operator==(Vector<3, T> const& v1, Vector<3, T> const& v2);
	template<typename T>
	constexpr bool operator!=(Vector<3, T> const& v1, Vector<3, T> const& v2);
	constexpr Vector<3, bool> operator&&(Vector<3, bool> const& v1, Vector<3, bool> const& v2);
	constexpr Vector<3, bool> operator||(Vector<3, bool> const& v1, Vector<3, bool> const& v2);

    // Binary bit-wise operators -- omitting for now
	// template<typename T>
	// constexpr Vector<3, T> operator&(Vector<3, T> const& v1, T scalar);

	// template<typename T>
	// constexpr Vector<3, T> operator&(Vector<3, T> const& v1, Vector<1, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator&(T scalar, Vector<3, T> const& v);

	// template<typename T>
	// constexpr Vector<3, T> operator&(Vector<1, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator&(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator|(Vector<3, T> const& v, T scalar);

	// template<typename T>
	// constexpr Vector<3, T> operator|(Vector<3, T> const& v1, Vector<1, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator|(T scalar, Vector<3, T> const& v);

	// template<typename T>
	// constexpr Vector<3, T> operator|(Vector<1, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator|(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator^(Vector<3, T> const& v, T scalar);

	// template<typename T>
	// constexpr Vector<3, T> operator^(Vector<3, T> const& v1, Vector<1, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator^(T scalar, Vector<3, T> const& v);

	// template<typename T>
	// constexpr Vector<3, T> operator^(Vector<1, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator^(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator<<(Vector<3, T> const& v, T scalar);

	// template<typename T>
	// constexpr Vector<3, T> operator<<(Vector<3, T> const& v1, Vector<1, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator<<(T scalar, Vector<3, T> const& v);

	// template<typename T>
	// constexpr Vector<3, T> operator<<(Vector<1, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator<<(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator>>(Vector<3, T> const& v, T scalar);

	// template<typename T>
	// constexpr Vector<3, T> operator>>(Vector<3, T> const& v1, Vector<1, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator>>(T scalar, Vector<3, T> const& v);

	// template<typename T>
	// constexpr Vector<3, T> operator>>(Vector<1, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator>>(Vector<3, T> const& v1, Vector<3, T> const& v2);

	// template<typename T>
	// constexpr Vector<3, T> operator~(Vector<3, T> const& v);

#include "vector3.inl"