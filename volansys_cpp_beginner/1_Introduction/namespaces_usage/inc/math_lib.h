// math_lib_v1.h
#ifndef MATH_LIB_H
#define MATH_LIB_H

namespace math_lib
{
    inline namespace math_lib_v1
    {
        int add(int a, int b);
    }
    inline namespace math_lib_v2
    {
        int add(int a, int b, int c); // New version adds a third parameter
    }
}

#endif // MATH_LIB_V1_H