
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

// Not heaps happy with this little function
bool RunSystemFunction(const char* cmd)
{
    FILE* fp = nullptr;
    int status; 
    char path[1000];
    fp = popen(cmd, "r");
    if (!fp)
    {   
        std::cerr << "Failed to run command: " << cmd << std::endl;
        return false;
    }   
    
    while (fgets(path, sizeof(path)-1, fp) != NULL)
    {   
        std::cout << path;
    }   
    return true;
}

int main(int, char**)
{
    std::cout << "input valid C++: ";
    std::string cpp;
    std::getline(cin, cpp);

    std::stringstream ss; 
    ss  << "#include <iostream>\n"
        << "extern \"C\" void entrypoint()\n"
        << "{\n"
        << cpp << ";\n"
        << "}" ;
    std::ofstream tmpCppFile;
    tmpCppFile.open("src/tmpCppFile.cpp", std::ios::out);
    tmpCppFile << ss.str();
    tmpCppFile.close();

    // I need to find a better way to call a sub process. I don't like that I'm basicly exec'ing
    // this is not good practice
    if (!RunSystemFunction("/usr/bin/g++ -c src/tmpCppFile.cpp -o src/tmpCppFile.o")) return 1;
    if (!RunSystemFunction("/usr/bin/g++ -shared src/tmpCppFile.o -o src/tmpCppFile.so")) return 1;

    // handle is a void* pointer
    auto handle = dlopen("./src/tmpCppFile.so", RTLD_LAZY);
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
    *(void**)(&test) = dlsym(handle, "entrypoint");

    auto error = dlerror();
    if(error != nullptr)
    {   
        std::cout << "error: " << error << std::endl;
    }   

    (*test)();
    dlclose(handle);
    return 0;
}
