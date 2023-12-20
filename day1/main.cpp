#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

std::vector<std::string> spelled = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void) {
    std::ifstream file("test.txt");
    std::string content;
    int res = 0;

    while (std::getline(file, content)) {
        int n = content.length();
        std::vector<char> digits;

        for (int i = 0; i < n; ++i) {
            if (isdigit(content[i])) {
                digits.push_back(content[i]);
            }
            for (int j = 0; i < spelled.size(); ++j) {
                if (content.substr(i, n).find(spelled[j]) != -1) {
                    digits.push_back(j+1+'0');
                }
            }
        }
        if (!digits.empty()) {
            std::string s = {digits.front(), digits.back()};
            res += std::stoi(s);
        }
    }
    std::cout << res << '\n';
}
