#include <fstream>
#include <iostream>
#include <string>

bool cubeCompare(std::string color, int num) {
    if (color == "red") {
        if (num <= 12) {
            return true;
        }
    } else if (color == "green") {
        if (num <= 13) {
            return true;
        }
    } else if (color == "blue") {
        if (num <= 14) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream infile("bag.txt");
    if (!infile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    int sumOfPossibleGames = 0;

    while (std::getline(infile, line)) {
        int gameID = 0;
        int failScore = 0;

        for (size_t i = 1; i <= line.length(); ++i) {
            if (line[i] == ';' || line[i] == ',' || line[i] == ':') {
                int firstPosNum = i + 2;
                size_t spacePos = line.find(' ', firstPosNum);
                std::string numStr = line.substr(firstPosNum, spacePos - firstPosNum);
                int num = std::stoi(numStr);

                size_t firstColorPos = spacePos + 1;
                size_t lastColorPos = line.find(' ', firstColorPos);
                std::string colorStr = line.substr(firstColorPos, lastColorPos - firstColorPos - 1);

                std::cout << "Number: " << num << " Color: " << colorStr;

                // Überprüfung der Kombination aus Farbe und Anzahl
                if (cubeCompare(colorStr, num)) {
                    std::cout << " (Valid)";
                } else {
                    std::cout << " (Invalid)";
                    failScore += 1;
                }

                std::cout << " Score: " << failScore << std::endl;

                // Wenn es sich um die ID handelt, speichere sie für weitere Verwendungszwecke
                if (line[i] == ':') {
                    int firstPosGameID = 5;
                    int lastPosGameID = i;
                    std::string gameIDStr = line.substr(firstPosGameID, lastPosGameID - firstPosGameID);
                    gameID = std::stoi(gameIDStr);
                    std::cout << "ID: " << gameID << std::endl;

                    // Füge gameID zur Summe nur hinzu, wenn keine ungültigen Kombinationen gefunden wurden
                    if (failScore == 0) {
                        sumOfPossibleGames += gameID;
                        std::cout << "Summe der möglichen Spiele: " << sumOfPossibleGames << std::endl;
                    }
                }
            }

            // Setze failScore für die nächste Zeile zurück
            failScore = 0;
        }
    }

    return 0;
}

