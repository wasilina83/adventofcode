#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

//Farbe und Anzahl extrairen
void extrColorAndNum(const std::string& line){
    std::istringstream iss(line);
    std::string token;
    std::vector<std::string> colors;
    std::vector<int> numbers;

    iss >> token;
    iss >> token;

    while (iss >> token){
        std::string color = "";
        int number = 0;
        size_t pos = token.find_first_of(",;");
       
        if (std::any_of(token.begin(), token.end(), ::isdigit) && pos != std::string::npos) {
        color = token.substr(0, pos);
        number = std::stoi(token.substr(pos + 1));
        }else {
            color = token;
        }
        colors.push_back(color);
        numbers.push_back(number);
    }
    for (size_t i = 0; i< colors.size(); ++i){
        std::cout << "Farbe: " << colors[i] << ", Zahl: " << numbers[i] << std::endl;
    }
}


int main() {
    std::string filename = "bag.txt";

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
       extrColorAndNum(line);
    }
    inputFile.close();
    return 0;
}
