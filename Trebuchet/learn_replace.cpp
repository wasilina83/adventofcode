#include <iostream>
#include <string>
#include <unordered_map>
#include <string_view>

std::unordered_map<std::string, int> spellOutDigits = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

int main() {
    std::string input = "onetwothreefourfivesixseveneightnine";

    for (const auto& pair : spellOutDigits) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    return 0;
}

