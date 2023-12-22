#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    int points = 0;

    while (std::getline(file, content)) {
        content = split(content, ':')[1];
        std::vector<std::string> cards = split(split(content, '|')[0], ' ');
        int cardsLength = cards.size();
        std::vector<std::string> winning = split(split(content, '|')[1], ' ');
        int winningLength = winning.size();

        int currPoints = 0;

        for (int i = 0; i < cardsLength; ++i) {
            for (int j = 0; j < winningLength; ++j) {
                if (!(cards[i].empty() || winning[j].empty())) {
                    int cardV = std::stoi(cards[i]);
                    int winningV = std::stoi(winning[j]);
                    if (cardV == winningV) {
                        std::cout << "card:" << cardV << " winning:" << winning[j] << '\n';
                        if (currPoints == 0) {
                            currPoints++;
                        } else {
                            currPoints *= 2;
                        }
                    }
                }
            }
        }
        points += currPoints;
    }


    std::cout << points << '\n';
    return 0;
}
