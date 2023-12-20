#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> max = {
    {"green", 0},
    {"blue", 0},
    {"red", 0},
};

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

int main(void) {
    std::ifstream file("input.txt");
    std::string content = "";
    int res = 0;

    while (std::getline(file, content)) {
        int n = content.length();
        const int gameId = std::stoi(split(split(content, ':')[0], ' ')[1]);

        std::vector<std::string> games = split(split(content, ':')[1], ';');
        for (std::string s : games) {
            std::vector<std::string> die = split(s, ',');
            for (std::string d : die) {
                const std::string count = split(d, ' ')[1];
                const std::string color = split(d, ' ')[2];

                if (std::stoi(count) > max[color]) {
                    max[color] = std::stoi(count);
                }
            }
        }
        res += max["red"] * max["green"] * max["blue"];
        max = {
            {"green", 0},
            {"blue", 0},
            {"red", 0},
        };
    }
    std::cout << res << '\n';
}
