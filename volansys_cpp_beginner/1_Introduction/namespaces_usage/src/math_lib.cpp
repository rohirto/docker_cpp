/**
 * @file math_lib_v1.cpp
 * @author rohirto
 * @brief demonstration of Inline namespaces
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 * In this example, the math_lib namespace introduces a new version (math_lib_v2) using the inline namespace feature. 
 * Existing code can continue to use the old version, and new code or code explicitly updated to use the new version can refer to it 
 * without explicitly using the namespace.
 * 
 */
#include "math_lib.h"

namespace math_lib
{
    inline namespace math_lib_v1
    {
        int add(int a, int b)
        {
            return a+b;
        }
    }
    inline namespace math_lib_v2
    {
        int add(int a, int b, int c) // New version adds a third parameter
        {
            return a+b+c;
        }
    }
}