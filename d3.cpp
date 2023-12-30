#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int dirs[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

typedef struct {
    int x;
    int y;
} coord;

std::vector<coord> lookAround(std::vector<std::string> arr, int y, int x) {
    std::vector<coord> coords;
    const int xMax = arr.size();
    const int yMax = arr[x].length();
    for (int i = 0; i < 8; ++i) {
        int newX = dirs[i][1];
        int newY = dirs[i][0];
        if ((y + newY) >= 0 && (x + newX) >= 0 && (y + newY) < yMax &&
            (x + newX) < xMax) {
            char c = arr[y + newY][x + newX];
            if (isdigit(c)) {
                coords.push_back({y+newY, x+newX});
            }
        }
    }
    return coords;
}

std::vector<coord> cleanUp(std::vector<coord> coords) {
    std::vector<coord> res;
    const int n = coords.size();
    int currX = -1;
    for (int i = 0; i < n; ++i) {
        if (currX != coords[i].x) {
            res.push_back(coords[i]);
            currX = coords[i].x;
        }
    }
    return res;
}

int traceBackNumber(std::vector<std::string> arr, int y, int x) {
    std::vector<char> buf;
    std::string res;
    while (isdigit(arr[y][x])) {
        std::cout << "curr " << arr[y][x] << '\n';
        buf.push_back(arr[y][x]);
        x++;
    }
    while (isdigit(arr[y][x])) {
        std::cout << "curr " << arr[y][x] << '\n';
        buf.insert(buf.begin(), arr[y][x]);
        x--;
    }

    const int n = buf.size();
    for (int i = 0; i < n; ++i) {
        std::cout << buf[i] << ' ';
        res += buf[i];
    }

    return 0;
}


int main(void) {
    std::ifstream file("test");
    std::string content = "";
    std::vector<std::string> arr;

    while (std::getline(file, content)) {
        arr.push_back(content);
    }

    std::vector<std::string> reg;
    const int n = arr.size();
    int res = 0;

    std::vector<coord> coords;

    for (int i = 0; i < n; ++i) {
        std::string buf = "";
        int valid = 0;
        for (int j = 0; j < arr[i].length(); ++j) {
            if (arr[i][j] == '*') {
                std::vector<coord> buf = lookAround(arr, i, j);
                if (buf.size() > 2) {
                    for (int i = 0; i < buf.size(); ++i) {
                        coords.push_back(buf[i]);
                    }
                }
            }
        }
    }
    coords = cleanUp(coords);
    for (int i = 0; i < coords.size(); ++i) {
        traceBackNumber(arr, coords[i].y, coords[i].x);
    }
    // std::cout << res << '\n';
    return 0;
}
