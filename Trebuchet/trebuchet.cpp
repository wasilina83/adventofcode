#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <unordered_map>


bool replace(std::string& str, const std::string& from, const std::string& to){
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;

}
int main(){
    std::ifstream infile("input-file.txt");
    std::string line;
    int number = 0;

    std::unordered_map<std::string, std::string> spellOutDigits = {
    {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
    {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
        };

    while (std::getline(infile, line)){
        std::string NewLine = line;
        for (const auto& pair : spellOutDigits){
            replace(NewLine, pair.first, pair.second);
            replace(NewLine, pair.first, pair.second);
            replace(NewLine, pair.first, pair.second);
            replace(NewLine, pair.first, pair.second);
            replace(NewLine, pair.first, pair.second);
            replace(NewLine, pair.first, pair.second);
            }
       // replace(NewLine, "one", "1");
       // replace(NewLine, "two", "2");
       // replace(NewLine, "three", "3");
       // replace(NewLine, "four", "4");
       // replace(NewLine, "five", "5");
       // replace(NewLine, "six", "6");
       // replace(NewLine, "seven", "7");
       // replace(NewLine, "eight", "8");
       // replace(NewLine, "nine", "9");
        auto firstNumberPosition = std::find_if(NewLine.begin(), NewLine.end(), ::isdigit);
        auto lastNumberPosition = std::find_if(NewLine.rbegin(), NewLine.rend(), ::isdigit);
        int firstNmberInLine =  *firstNumberPosition - '0';
        int lastNumberInLine = *lastNumberPosition - '0';
        int lineNumber = firstNmberInLine*10+lastNumberInLine;
        number = number+lineNumber;
    std::cout<<"Newline:"<<NewLine <<"\n-Line:"<< line << ':' << firstNmberInLine <<" & " << lastNumberInLine << '\n';
    }
    std::cout<< number;
}


