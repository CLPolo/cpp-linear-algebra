// Define length type for clarity
typedef int length_t;

// Specify vector template
template <length_t L, typename T> struct Vector;

// Specify matrix template w/ C columns and R rows
template <length_t C, length_t R, typename T> struct Matrix;

// Specify quaternion template
template <typename T> struct Quat;

// Setup template aliases -- Vectors
template<typename T> using Vector1 = Vector<1, T>;
template<typename T> using Vector2 = Vector<2, T>;
template<typename T> using Vector3 = Vector<3, T>;
template<typename T> using Vector4 = Vector<4, T>;

// Setup template aliases -- 2 x R matrices
template<typename T> using Matrix2   = Matrix<2, 2, T>;
template<typename T> using Matrix2x2 = Matrix<2, 2, T>;
template<typename T> using Matrix2x3 = Matrix<2, 3, T>;
template<typename T> using Matrix2x4 = Matrix<2, 4, T>;

// Setup template aliases -- 3 x R matrices
template<typename T> using Matrix3   = Matrix<3, 3, T>;
template<typename T> using Matrix3x2 = Matrix<3, 2, T>;
template<typename T> using Matrix3x3 = Matrix<3, 3, T>;
template<typename T> using Matrix3x4 = Matrix<3, 4, T>;

// Setup template aliases -- 4 x R matrices
template<typename T> using Matrix4   = Matrix<4, 4, T>;
template<typename T> using Matrix4x2 = Matrix<4, 2, T>;
template<typename T> using Matrix4x3 = Matrix<4, 3, T>;
template<typename T> using Matrix4x4 = Matrix<4, 4, T>;