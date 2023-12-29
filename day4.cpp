#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef struct {
    std::string value;
    int mult;
} card;

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
    std::ifstream file("input");
    std::string content;
    std::vector<card> arr;

    int points = 0;

    while (std::getline(file, content)) {
        card c;
        c.value = content;
        c.mult = 1;
        arr.push_back(c);
    }

    for (int i = 0; i < arr.size(); ++i) {
        std::string s = split(arr[i].value, ':')[1];
        std::vector<std::string> cards = split(split(s, '|')[0], ' ');
        int cardsLength = cards.size();
        std::vector<std::string> winning = split(split(s, '|')[1], ' ');
        int winningLength = winning.size();

        int currPoints = 0;
        for (int i = 0; i < cardsLength; ++i) {
            for (int j = 0; j < winningLength; ++j) {
                if (!(cards[i].empty() || winning[j].empty())) {
                    int cardV = std::stoi(cards[i]);
                    int winningV = std::stoi(winning[j]);
                    if (cardV == winningV) {
                        currPoints++;
                    }
                }
            }
        }

        for (int j = 0; j < currPoints; ++j) {
            int n = i+j+1;
            arr[n].mult = arr[n].mult + arr[i].mult;
        }

    }

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i].value;
        std::cout << " M: " << arr[i].mult << '\n';
        points += arr[i].mult;
    }

    std::cout << points << '\n';
    return 0;
}
