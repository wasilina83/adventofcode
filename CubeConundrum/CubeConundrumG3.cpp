#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

bool containsOnlyDigits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void extractColorsAndNumbers(const std::string& line, std::map<std::string, int>& maxValues) {
    std::istringstream iss(line);
    std::string token;
    
    iss >> token;
    iss >> token;

    while (iss >> token) {
        std::string color = "";
        int number = 0;
        size_t pos = token.find_first_of(",;");
        
        // Überprüfe, ob der Token sowohl Buchstaben als auch Ziffern enthält
        if (containsOnlyDigits(token) && pos != std::string::npos) {
            color = token.substr(0, pos);
            number = std::stoi(token.substr(pos + 1));
            
            // Aktualisiere den maximalen Wert für diese Farbe, wenn nötig
            if (number > maxValues[color]) {
                maxValues[color] = number;
            }
        }
    }
}

int main() {
    std::string filename = "bag.txt";  // Ändere den Dateinamen nach Bedarf
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
        return 1;
    }

    std::string line;
    std::map<std::string, int> maxValues = {{"red", 0}, {"blue", 0}, {"green", 0}};

    while (std::getline(inputFile, line)) {
        // Extrahiere Farben und Zahlen und aktualisiere die maximalen Werte
        extractColorsAndNumbers(line, maxValues);
    }

    // Gib die finalen maximalen Werte aus
    std::cout << "Finale maximale Werte: ";
    for (const auto& pair : maxValues) {
        std::cout << pair.first << ": " << pair.second << ", ";
    }
    std::cout << std::endl;

    inputFile.close();

    return 0;
}

