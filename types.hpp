#define ASSERT_LENGTH(l, max) (assert ((l) >= 0 && (l) < (max)))

// Define length type for clarity
typedef int length_t;

// Specify general type templates
template <                        typename T> struct Quaterion;
template <length_t L,             typename T> struct Vector;
template <length_t C, length_t R, typename T> struct Matrix;

// Define explicit and general vector types - floats
typedef Vector<1, float> Vector1;
typedef Vector<2, float> Vector2;
typedef Vector<3, float> Vector3;
typedef Vector<4, float> Vector4;

typedef Vector1 genFType;
typedef Vector2 genFType;
typedef Vector3 genFType;
typedef Vector4 genFType;

// Define explicit and general vector types - doubles
typedef Vector<1, double> dVector1;
typedef Vector<2, double> dVector2;
typedef Vector<3, double> dVector3; 
typedef Vector<4, double> dVector4; 

typedef dVector1 genDType;
typedef dVector2 genDType;
typedef dVector3 genDType;
typedef dVector4 genDType;

// Define explicit and general vector types - integers
typedef Vector<1, int> iVector1;
typedef Vector<2, int> iVector2;
typedef Vector<3, int> iVector3;
typedef Vector<4, int> iVector4;

typedef iVector1 genIType;
typedef iVector2 genIType;
typedef iVector3 genIType;
typedef iVector4 genIType;

// Define explicit and general vector types - u32
typedef Vector<1, unsigned int> uVector1;
typedef Vector<2, unsigned int> uVector2;
typedef Vector<3, unsigned int> uVector3;
typedef Vector<4, unsigned int> uVector4;

typedef uVector1 genUType;
typedef uVector2 genUType;
typedef uVector3 genUType;
typedef uVector4 genUType;


// Define explicit and general vector types - boolean
typedef Vector<1, bool> bVector1;
typedef Vector<2, bool> bVector2;
typedef Vector<3, bool> bVector3;
typedef Vector<4, bool> bVector4;

typedef bVector1 genBType;
typedef bVector2 genBType;
typedef bVector3 genBType;
typedef bVector4 genBType;

// // Define the general vector type
// template <length_t L> using genType  = Vector<L, float>;
// template <length_t L> using genDType = Vector<L, double>;
// template <length_t L> using genIType = Vector<L, int>;
// template <length_t L> using genUType = Vector<L, unsigned>;
// template <length_t L> using genBType = Vector<L, bool>;

// Define explicit 2 x R matrix types
typedef Matrix<2, 2, float> Matrix2;
typedef Matrix<2, 2, float> Matrix2x2;
typedef Matrix<2, 3, float> Matrix2x3;
typedef Matrix<2, 4, float> Matrix2x4;

typedef Matrix<2, 2, double> dMatrix2;
typedef Matrix<2, 2, double> dMatrix2x2;
typedef Matrix<2, 3, double> dMatrix2x3;
typedef Matrix<2, 4, double> dMatrix2x4;

// Define explicit 3 x R matrix types
typedef Matrix<3, 3, float> Matrix3;
typedef Matrix<3, 2, float> Matrix3x2;
typedef Matrix<3, 3, float> Matrix3x3;
typedef Matrix<3, 4, float> Matrix3x4;

typedef Matrix<3, 3, double> dMatrix3;
typedef Matrix<3, 2, double> dMatrix3x2;
typedef Matrix<3, 3, double> dMatrix3x3;
typedef Matrix<3, 4, double> dMatrix3x4;

// // Setup template aliases -- 4 x R matrices
// template<typename T> using Matrix4   = Matrix<4, 4, T>;
// template<typename T> using Matrix4x2 = Matrix<4, 2, T>;
// template<typename T> using Matrix4x3 = Matrix<4, 3, T>;
// template<typename T> using Matrix4x4 = Matrix<4, 4, T>;

// Define explicit 4 x R matrix types
typedef Matrix<4, 4, float> Matrix3;
typedef Matrix<4, 2, float> Matrix4x2;
typedef Matrix<4, 3, float> Matrix4x3;
typedef Matrix<4, 4, float> Matrix4x4;

typedef Matrix<4, 3, double> dMatrix4;
typedef Matrix<4, 2, double> dMatrix4x2;
typedef Matrix<4, 3, double> dMatrix4x3;
typedef Matrix<4, 4, double> dMatrix4x4;

// Define explicit quaterion types
typedef Quaterion<float>  Quaternion;
typedef Quaterion<double> dQuaternion;