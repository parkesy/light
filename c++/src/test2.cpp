
#include <iostream>
#include "src/getNumber.hpp"

extern "C" void test()
{
    std::cout << GetNumber() << std::endl;
}
