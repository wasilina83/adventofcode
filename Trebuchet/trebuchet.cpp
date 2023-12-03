#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <unordered_map>


std::unordered_map<std::string, int > spellOutDigits = {
    {"zero", 0}, {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9}
};

int main(){
    std::ifstream infile("input-file.txt");
    std::string line;
    int number = 0;

    while (std::getline(infile, line)){
        for (const auto& pair : spellOutDigits){
            size_t pos = line.find(pair.first);
            if (pos != std::string::npos){
                firstNmberInLine = pair.second;
                break;
            }
        }
        for (auto it = spellOutDigits.rbegin(); it != spellOutDigits.rend(); ++it){
            size_t pos = line.rfind(it->first);
            if (pos != std::string::npos){

            }
        }
        auto firstNumberPosition = std::find_if(line.begin(), line.end(), ::isdigit);
        auto lastNumberPosition = std::find_if(line.rbegin(), line.rend(), ::isdigit);
        int firstNmberInLine =  *firstNumberPosition - '0';
        int lastNumberInLine = *lastNumberPosition - '0';
        int lineNumber = firstNmberInLine*10+lastNumberInLine;
        number = number+lineNumber;
        std::cout << line << ':' << firstNmberInLine <<" & " << lastNumberInLine << '\n';
    }
    std::cout<< number;
}


