
#include <iostream>
#include <dlfcn.h>
using namespace std;

int main(int, char**)
{
    // handle is a void* pointer
    auto handle = dlopen("./src/test.so", RTLD_LAZY);
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

    (*test)();
    dlclose(handle);
    return 0;
}
