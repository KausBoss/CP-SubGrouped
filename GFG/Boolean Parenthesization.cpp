#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
 
int main()
{
    fs::path p = fs::current_path();
 
    std::cout << "The current path " << p << " decomposes into:\n"
              << "root-path " << p.root_path() << '\n'
              << "relative path " << p.relative_path() << '\n';
}