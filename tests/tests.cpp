#include <iostream>
#include <typeinfo>
#include "linalg.hpp"

int main()
{   
    int errorCount = 0;
    int errorStart = errorCount;

    std::cout << "---------------------------------------\n";
    std::cout << "             Vector2 Tests\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Testing constructors:\tVector2 v1 = Vector2()\n\
                      \tVector2 v2 = Vector2(3.0f, 2)\n\
                      \tVector2 v3 = Vector2(v2)\n";
    
    Vector2 v1 = Vector2();
    Vector2 v2 = Vector2(3.0f, 2);
    Vector2 v3 = Vector2(v2);

    std::cout << "v1:\n";
    v1.printVectorDetailed();
    std::cout << "v2\n";
    v2.printVectorDetailed();
    std::cout << "v3:\n";
    v3.printVectorDetailed();



    // Have the elements of v1 been initialized to 0.0f?
    if (v1.x != 0.0f && typeid(v1.x) == typeid(float))
    {
        std::cerr << "\tFailed to initialize v1.x to 0:  v1.x = " << v1.x << "\n";
        errorCount += 1;
    }
    if (v1.y != 0.0f)
    {
        std::cerr << "\tFailed to initialize v1.y to 0:  v1.y = " << v1.y << "\n";
        errorCount += 1;
    }
    std::cout << "\t\tv1.x = " << v1.x << "  v1.y = " << v1.y << "\n";
    std::cout << "\tSuccessfully initilized x and y to 0.0f\n\n";

    std::cout << "Testing constructor:\n\tVector2 v1 = Vector((int) 1);\n";

    v1 = Vector2((int)1);

    // Have the elements of v1 been initialized to 1.0f?
    if (v1.x != 1.0f)
    {
        std::cerr << "\tFailed to initialize v1.x to 1.0:  v1.x = " << v1.x << "\n";
        errorCount += 1;
    }
    if (v1.y != 1.0f)
    {
        std::cerr << "\tFailed to initialize v1.y to 1.0:  v1.y = " << v1.y << "\n";
        errorCount += 1;
    }

    v1.printVectorDetailed();
    std::cout << "\tSuccessfully initilized x and y to 1.0f\n\n";

    std::cout << "Testing constructor:\n\tVector2 v1 = Vector((int 2), (int 3));\n";

    v1 = Vector2((int) 2, (int) 3);

    // Have the elements of v1 been initialized to x = 2.0f and y = 3.0f?
    if (v1.x != 2.0f)
    {
        std::cerr << "\tFailed to initialize v1.x to 2.0:  v1.x = " << v1.x << "\n";
        errorCount += 1;
    }
    if (v1.y != 3.0f)
    {
        std::cerr << "\tFailed to initialize v1.y to 3.0:  v1.y = " << v1.y << "\n";
        errorCount += 1;
    }
    v1.printVectorDetailed();
    std::cout << "\tSuccessfully initilized v1.x to 2.0f and v1.y to 3.0f\n\n";
    if (errorCount == errorStart)
    {
        std::cout << "Vector2 constructor tests passed. Total errors: " << errorCount <<std::endl;
    }

    // std::cout << "Testing constructor:\tdVector2 v2 = dVector2();\n";
    
    // dVector2 v2 = dVector2();
    return 0;
}