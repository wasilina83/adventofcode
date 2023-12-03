#include <fstream>
#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

bool stillContains(std::auto& it, line.end(), color.begin(), color.end())
{
    // str.find() (or str.contains(), since C++23) can be used as well
    std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
    return true
}


int main() {
    std::ifstream infile("bag.txt");
    std::string line;

    int sumOfPossibleGames = 0;
    int colorPos = 0;
    while (std::getline(infile, line)) {
        // Find the game ID in the line
        auto pos = line.find("Game ");
        if (pos != std::string::npos) {
            int gameId = std::stoi(line.substr(pos + 5, line.find(":") - pos - 5));
            //std::cout<< gameId;
            // Read the subsets of cubes for the current game
            int redCubes = 0, greenCubes = 0, blueCubes = 0;
            std::vector <std::string> colors = {"red", "green","blue"};
            for (const auto& color : colors) {
               while (std::search(it, line.end(), color.begin(), color.end())==true)
               {
                    const auto it = std::search(line.begin(), line.end(), color.begin(), color.end());
                    int colorPos = std::distance(line.begin(), it);
                    std::cout<<color<<':'<<colorPos<<'\n';
                }
            }

            // Check if the game is possible
           // if (redCubes == 12 && greenCubes == 13 && blueCubes == 14) {
             //   sumOfPossibleGames += gameId;

        }
    }

    std::cout << "Sum of possible games: " << sumOfPossibleGames << std::endl;

    return 0;
}

