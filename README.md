# Basic C++ Linear Algebra Library

## Overview
This is my implementation of a C++ linear algebra library, currently a work in progress. This library was created with three goals in mind:
 1. To learn and be introduced to relevant modern C++ functionality, namely [operator overloading](https://en.cppreference.com/w/cpp/language/operators), [function templates](https://en.cppreference.com/w/cpp/language/function_template) and [template specialization](https://en.cppreference.com/w/cpp/language/template_specialization), and [constructors](https://en.cppreference.com/w/cpp/language/constructor).

 2. To become familiar with the [GLSL specification](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.40.pdf) by aiming for this library adhere to it as best as I can.

 3. To develop a deeper understanding of both linear agebra and its application in graphics. 

To these ends, this document and source comments will serve as a space to record what I have learned. Thus, concepts which may seem self evident to the experienced C++ and/or graphics programmer will be expounded on in detail. If, dear reader, you notice errors in my implementation or understanding, then please feel free to reach out and let me know. 

This library is heavily based on the [OpenGL Mathematics (glm)](https://github.com/g-truc/glm) library. It will be referenced often as it is (currently) my primary source for exposure to the relevant C++. 



## Specification Requirements
The GLSL specification supports a [wide variety of types](https://www.khronos.org/opengl/wiki/Data_Type_(GLSL)). For our purposes, we will implement the following:

### Vectors
| GLSL syntax | our syntax | type definition |
|-------------|------------|-----------------|
| bvec*n* | bVector*n* | a vector of booleans |
| ivec*n* | iVector*n* | a vector of signed integers |
| uvec*n* | uVector*n* | a vector of unsigned integers |
| vec*n* | Vector*n* | a vector of floats |
| dvec*n* | dVector*n* | a vector of doubles |

The *n*'s above can be 2, 3, or 4, indicating the number of elements the vector is comprised of.

### Matrices
| GLSL syntax | our syntax | type definition |
|-------------|------------|-----------------|
| mat*n*x*m* | Matrix*n*x*m* | a matrix of floats with *n* columns and *m* rows |
| mat*n* | Matrix*n* | shorthand for an *n* by *n* matrix of floats |
| dmat*n*x*m* | dMatrix*n*x*m* | a matrix of doubles with *n* columns and *m* rows |
| dmat*n* | dMatrix*n* | shorthand for an *n* by *n* matrix of doubles |

The *n*'s and *m*'s above can be 2, 3, or 4, indicating the number of columns or rows comprising the matrix.


### Type conversion and constructors
Sections 4.1.10-.11 and sections 5.4.1-.2 of the specification describe the supported type conversions, initializers, and constructors. We aim to support the conversions and constructors listed in the specification. Some examples from section 5.4:

    Vectors
                      
        vec3(float) // initializes each component of the vec3 with the float
        vec4(ivec4) // makes a vec4 with component-wise conversion
        vec4(mat2)  // the vec4 is column 0 followed by column 1

        vec2(float, float)            // initializes a vec2 with 2 floats
        ivec3(int, int, int)          // initializes an ivec3 with 3 ints
        bvec4(int, int, float, float) // uses 4 Boolean conversions
    
        vec2(vec3) // drops the third component of a vec3
        vec3(vec4) // drops the fourth component of a vec4
    
    Matrices

        mat3(float) // initializes the diagonal of the matix to the float 
                    // with all other elements set to zero

        mat2(vec2, vec2);             // one column per argument
        mat3(vec3, vec3, vec3);       // one column per argument
        mat4(vec4, vec4, vec4, vec4); // one column per argument
        mat3x2(vec2, vec2, vec2);     // one column per argument
               
        mat2(float, float,     // first column
             float, float);    // second column
    
        mat2x3(vec2, float,    // first column
               vec2, float);   // second column
        
        dmat2x4(dvec3, double, // first column
                double, dvec3) // second column

### Built-in Functions
Section 8 of the GLSL specification lists the supported built-in functions. As per the specification, a general type will be used for functions which can take a vector of any dimension:

| valid input arguments | general type syntax |
|-----------------------|---------------------|
| float, Vector2, Vector3, Vector4 | *genType* |
| int, iVector2, iVector3, iVector4 | *genIType* |
| uint, uVector2, uVector3, uVector4 | *genUType* |
| bool, bVector2, bVector3, bVector4 | *genBType* |
| double, dVector2, dVector3, dVector4 | *genDType* |

We will be implementing the following functions:

**Angles and Trigonometry** - GLSL Spec Section 8.1

*The following are all component-wise operations*

| Syntax | Description |
|--------|-------------|
| <pre lang="cpp">genType radians(genType *degrees*)</pre> | Converts degrees to radians i.e. $\displaystyle{\frac{\pi}{180}}\cdot degrees $ |
| <pre lang="cpp">genType degrees(genType *radians*)</pre> | Converts  radians to degrees i.e. $\displaystyle{\frac{180}{\pi}}\cdot radians $ |
| <pre lang="cpp">genType sin(genType *angle*)<br>        cos(genType *angle*)<br>        tan(genType *angle*)</pre> | The standard sine, cosine, and tangent trigonometric functions. |
| <pre lang="cpp"> genType asin(genType *x*)</pre> | Returns an angle, $\theta$, in radians, whose sine is *x* where <br>$\theta\in\displaystyle{\Big[-\frac{\pi}{2},\frac{\pi}{2}\Big]}$. Results are undefined if $\lvert x\rvert > 1$. |
| <pre lang="cpp"> genType acos(genType *x*)</pre> | Returns an angle, $\theta$, in radians, whose cosine is *x* where <br>$\theta\in\displaystyle{\big[0,\pi\big]}$. Results are undefined if $\lvert x\rvert > 1$.  |
| <pre lang="cpp"> genType atan(genType *y*, genType *x*)</pre> | Returns an angle, $\theta$, in radians, whose tangent is $y/x$. where $\theta\in\displaystyle{\big[-\pi,\pi\big]}$. The signs of $x$ and $y$ determine the quadrant of $\theta$. Results are undefined if $x$ and $y$ are both $0$.|
| <pre lang="cpp"> genType atan(genType *y_over_x*)</pre> | Returns an angle, $\theta$, in radians, whose tangent is *y_over_x*. where $\theta\in\displaystyle{\Big[-\frac{\pi}{2},\frac{\pi}{2}\Big]}$. |
| <pre lang="cpp"> genType sinh(genType *x*)</pre> | Returns the hyperbolic sine function: $\displaystyle{\frac{e^x-e^{-x}}{2}}$|
| <pre lang="cpp"> genType cosh(genType *x*)</pre> | Returns the hyperbolic cosine function: $\displaystyle{\frac{e^x+e^{-x}}{2}}$|
| <pre lang="cpp"> genType tanh(genType *x*)</pre> | Returns the hyperbolic tangent function: $\displaystyle{\frac{sinh(x)}{cosh(x)}}$|
| <pre lang="cpp"> genType asinh(genType *x*)</pre> | Returns the inverse of sinh.|
| <pre lang="cpp"> genType acosh(genType *x*)</pre> | Returns the non-negative inverse of cosh. Results are undefined if $x < 1$.|
| <pre lang="cpp"> genType atanh(genType *x*)</pre> | Returns the inverse of tanh. Results are undefined if $\lvert x\rvert\ge1$.|