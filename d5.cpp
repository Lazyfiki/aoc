#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream file("test");
    std::string content;
    while (std::getline(file, content)) {
        std::cout << content << '\n';
    }
    return 0;
}
