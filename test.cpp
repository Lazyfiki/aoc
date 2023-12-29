#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int test = 1;

    for (int i = 0; i < arr.size(); ++i) {
        if (test) {
            for (int j = 0; j < 4*2; ++j) {
                arr.insert(arr.begin() + i+j+1, arr[i+j+1]);
                j++;
            }
            test--;
        }
        std::cout << arr[i] << '\n';
    }
}
