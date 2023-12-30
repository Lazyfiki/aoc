#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::vector<std::pair<std::string, int>> spelled = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
    {"seven", 7}, {"eight", 8}, {"nine", 9}
};

std::vector<std::string> extractDigitsAndSpelled(const std::string& content) {
    std::vector<std::string> result;
    int n = content.length();

    for (int i = 0; i < n; ++i) {
        if (isdigit(content[i])) {
            result.push_back(std::string(1, content[i]));
        } else {
            for (const auto& entry : spelled) {
                const std::string& spelledNumber = entry.first;
                if (content.substr(i, spelledNumber.length()) == spelledNumber) {
                    result.push_back(std::to_string(entry.second));
                    i += spelledNumber.length() - 1;
                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    std::ifstream file("input.txt");
    std::string content;
    int res = 0;

    while (std::getline(file, content)) {
        std::vector<std::string> result = extractDigitsAndSpelled(content);
        std::string s = result.front() + result.back();
        res += std::stoi(s);
    }
    std::cout << res << '\n';
    return 0;
}

