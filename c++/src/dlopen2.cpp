
#include <iostream>
#include <dlfcn.h>

#include "src/getNumber.hpp"

int main(int, char**)
{
    std::cout << "GetNumber Test1: " << GetNumber() << std::endl;
    // handle is a void* pointer
    auto handle = dlopen("./src/test2.so", RTLD_LAZY);
    if (!handle)
    {
        std::cout << "error: " << dlerror() << std::endl;
        return 1;
    }
    // This call to dlerror is meant to clear any remaining errors
    // it looks really clunky. I wish I didn;t have to call this 
    // if the handle is not NULL
    dlerror(); 

    // create a function pointer handle
    void (*test)();
    *(void**)(&test) = dlsym(handle, "test");

    auto error = dlerror();
    if(error != nullptr)
    {
        std::cout << "error: " << error << std::endl;
    }

    std::cout << "GetNumber Test2: ";
    (*test)();
    dlclose(handle);
    return 0;
}
