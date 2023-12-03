#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>
#include <fstream>

using namespace std::literals;

bool contains(const auto& cont, std::string_view s)
{
    // str.find() (or str.contains(), since C++23) can be used as well
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

int main()
{
    // The C++17 overload with searchers demo:
    std::ifstream infile("input-file.txt");
    std::string line;

    while(std::getline(infile, line)){
     for (const auto word : {"zero"sv, "one"sv, "two"sv, "three"sv, "four"sv, "five"sv, "six"sv, "seven"sv, "eight"sv, "nine"sv, }){
            std::cout << "The string " << std::quoted(word) << ' ';
            const std::boyer_moore_searcher searcher(word.begin(), word.end());
            const auto it = std::search(line.begin(), line.end(), searcher);
            std::cout << line;
            if (it == line.end())
                std::cout << "not found\n";
            else
                std::cout << "found at offset " << std::distance(line.begin(), it) << '\n';
    }}
}

