#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const int dirs[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

bool
isDot(char c)
{
    return c == '.';
}

std::vector<std::vector<int>>
lookAround(std::vector<std::string> map, int y, int x, int yMax, int xMax)
{
    std::vector<std::vector<int>> coords = {};
    for (int i = 0; i < 8; ++i) {
        int newX = dirs[i][1];
        int newY = dirs[i][0];
        if ((y + newY) >= 0 && (x + newX) >= 0 && (y + newY) < yMax &&
            (x + newX) < xMax) {
            char c = map[y + newY][x + newX];
            if (isdigit(c)) {
                coords.push_back({y+newY, x+newX});
            }
        }
    }
    return coords;
}

std::vector<std::vector<int>>
filterNumbers(std::vector<std::string> map, int y, int x)
{
    std::vector<std::vector<int>> res = {};
    if () {
        std::vector<int> coords = {y, x};
        res.push_back(coords);
    }

    return res;
}

int
main(void)
{
    std::ifstream file("test.txt");
    std::string content = "";
    std::vector<std::string> map;

    while (std::getline(file, content)) {
        map.push_back(content);
    }

    std::vector<std::string> reg;
    const int n = map.size();
    int res = 0;


    for (int i = 0; i < n; ++i) {
        std::string buf = "";
        int valid = 0;
        const int m = map[i].length();
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '*') {
                std::vector<std::vector<int>> coords = lookAround(map, i, j, n, m);
                for (int i = 0; i < coords.size(); ++i) {
                    std::cout << "x:" << coords[i][0];
                    std::cout << ", y:" << coords[i][1] << '\n';
                }
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}
