#include <iostream>
#include <fstream>
#include <string>
#include <map>

const int rMax = 12;
const int gMax = 13;
const int bMax = 14;

std::map<char, int> rgb(std::string content) {
    int n = content.length();
    std::map<char, int> rgbVal = {
        {'r', 0},
        {'g', 0},
        {'b', 0},
    };

    std::string buf = "";
    for (int i = 0; i < content.length(); ++i) {
        char c = content[i];
        if (isdigit(c)) {
            buf += c;
        } else if (c == 'r' || c == 'g' || c == 'b') {
            try {
                rgbVal[c] += std::stoi(buf);
                buf = "";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << " for character '" << c << "' at position " << i << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << " for character '" << c << "' at position " << i << std::endl;
            }
        }
    };
    return rgbVal;
}

int main(void) {
    std::ifstream file("input.txt");
    std::string content = "";
    int idx = 1;
    int res = 0;

    while (std::getline(file, content)) {
        int n = content.length();
        size_t pos = content.find(":");
        content = content.substr(pos+2, n);
        std::cout << idx << ' ' << content << '\n';

        std::map<char, int> rgbVal = rgb(content);
        if ( rgbVal['r'] <= rMax && rgbVal['g'] <= gMax && rgbVal['b'] <= bMax) {
            res += idx;
        }

        idx++;
    }
    std::cout << res << '\n';
}
