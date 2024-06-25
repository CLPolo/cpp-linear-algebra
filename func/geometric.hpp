
#pragma once
#include "../types.hpp"
#include "../vectors/vector3.hpp"

// Returns the length of vector x
template <typename genType>
float length(genType v)
{   
    // The length or magnitude of a vector a = [a1, a2, ..., an] is given by:
    //
    // sqrt(a1^2 + a2^2 + ... + an^2)
    //
    // This is the generalization of the pythagorean theorem for determining
    // the side lengths of a right triangle
    float return_length = 0;
    int i = 0;

    while (i < v.length())
    {
        switch (i)
        {
            case 0:
                return_length += pow(v.x, 2);
                break;
            case 1;
                return_length += pow(v.y, 2);
                break;
            case 2:
                return_length += pow(v.z, 2);
                break;
            case 3:
                return_length += pow(v.w, 2);
                break;
        }
        i += 1;
    }

    return sqrt(return_length);
}

template <typename genDType>
double length(genDType v)
{
    double return_length = 0;
    int i = 0;

    while (i < v.length())
    {
        switch (i)
        {
            case 0:
                return_length += pow(v.x, 2);
                break;
            case 1;
                return_length += pow(v.y, 2);
                break;
            case 2:
                return_length += pow(v.z, 2);
                break;
            case 3:
                return_length += pow(v.w, 2);
                break;
        }
        i += 1;
    }

    return sqrt(return_length);
}

// Returns the distance between two vectors
template <typename genType>
float distance(genType p0, genType p1)
{
    // Example:
    // Let p0 = (3, 5, 5) and p1 = (0, 5, 9)
    // p0 - p1 = (3, 0, -4)
    //     length(3, 0, -4) = sqrt(9 + 0 + 16)
    //                        sqrt(25) = 5
    // return 5
    return length(p0 - p1);
}

template <typename genDType>
double distance(genDType p0, genDType p1) {return length(p0 - p1);}

// Returns the dot product of a and b
template <typename genType>
float dot(genType a, genType b)
{   
    //--------------------------------------------------
    // Coordinate definition of the dot product
    //
    // a dot b := sum from i = 1 to n of ai*bi 
    //
    // where ai is an element of a, and
    //       bi is an element of b
    //
    // Example:
    //      let a = (1, 2, 3) and b = (7, 8, 9), then
    //
    //      dot(a, b) = 1*7 + 2*8 + 3*9
    //                  =   7 +  16 +  27
    //                  = 50
    float return_dot = 0;
    int i = 0;

    while (i < a.length() && i < b.length())
    {
        switch (i):
        {
            case 0:
                return_dot += a.x*b.x;
                break;
            case 1:
                return_dot += a.y*b.y;
                break;
            case 2:
                return_dot += a.z*b.z;
                break;
            case 3:
                return_dot += a.w*b.w;
                break;
        }
        i += 1;
    }
    return return_dot;    
}

template <typename genDType>
double dot(genDType a, genDType b)
{   
    //--------------------------------------------------
    // Coordinate definition of the dot product
    //
    // a dot b := sum from i = 1 to n of ai*bi 
    //
    // where ai is an element of a, and
    //       bi is an element of b
    //
    // Example:
    //      let a = (1, 2, 3) and b = (7, 8, 9), then
    //
    //      dot(a, b) = 1*7 + 2*8 + 3*9
    //                  =   7 +  16 +  27
    //                  = 50
    double return_dot = 0;
    int i = 0;

    while (i < a.length() && i < b.length())
    {
        switch (i):
        {
            case 0:
                return_dot += a.x*b.x;
                break;
            case 1:
                return_dot += a.y*b.y;
                break;
            case 2:
                return_dot += a.z*b.z;
                break;
            case 3:
                return_dot += a.w*b.w;
                break;
        }
        i += 1;
    }
    return return_dot;    
}

Vector3 cross(Vector3 a, Vector3 b)
{
    // Given two vectors, a and b, in 3-space, the cross product is defined
    // as a third vector c which is perpendicular to both a and b and whose
    // length is proportional to the angle between them. It is given by the
    // formula
    //
    //      a x b = ||a||*||b||*sin(theta)*n
    // where
    //      theta is the angle between a and b in the plane containing them.
    //      ||a|| and ||b|| are the magnitudes of vectors a and b, and
    //      n is a unit vector perpendicular to a and b
    //
    // if a and b are parallel,  a x b = 0 i.e. the zero vector and ||a x b|| = 0
    // if a and b are orthogonal ||a x b|| = ||a||*||b||
    //
    // -------------------------------------------------------------------------------
    //      Computing the cross product
    // -------------------------------------------------------------------------------
    //
    // If i, j, k is an orthonormal basis of R3, i.e. i = (1, 0, 0), j = (0, 1, 0),
    // and k = (0, 0, 1), then the following equalities are satisfied:
    //
    //      i x j = k       j x i = -k       a = (a1, a2, a3) = a1*i + a2*j + a3*k
    //      j x k = i       k x j = -i       b = (b1, b2, b3) = b1*i + b2*j + b3*k
    //      k x i = j       i x k = -j
    //
    // Thus, for any two vectors a and b,
    //
    //      a x b = (a1*i + a2*j + a3*k) x (b1*i + b2*j + b3*k) =
    //
    //            = a1*b1(i x i) + a1*b2(i x j) + a1*b3(i x k) +
    //              a2*b1(j x i) + a2*b2(j x j) + a2*b3(j x k) +
    //              a3*b1(k x i) + a3*b2(k x j) + a3*b3(k x k)      by distributivity
    //
    //            = a1*b1*0 + a1*b2*k - a1*b3*j +
    //             -a2*b1*k + a2*b2*0 + a2+b3*i +
    //              a3*b1*j - a3*b2*i + a3*b3*0
    //
    //            = (a2*b3 - a3*b2)*i +         |n1|    |a2*b3 - a3*b2|
    //              (a3*b1 - a1*b3)*j +   ==>   |n2| =  |a3*b1 - a1*b3|
    //              (a1*b2 - a2*b1)*k           |n3|    |a1*b2 - a2*b1| by linearity
    //
    //  Example
    //      let a = (1, 2, 3) and b = (4, 5, 6), then
    //
    //      a x b = ((2*6 - 3*5), (3*4 - 1*6), (1*5 - 2*4)) 
    //            = (( 12 - 15 ), ( 12 - 6  ), (  5 - 8  ))
    //            = (-3, 6, -3)
    // -----------------------------------------------------------------------------------
    // see: https://en.wikipedia.org/wiki/Cross_product
    //------------------------------------------------------------------------------------
    
    Vector3 a = Vector3();

    return Vector3(a.y*b.z - a.z*b.y,
                   a.z*b.x - a.x*b.z,
                   a.x*b.y - a.y*b.x);
}