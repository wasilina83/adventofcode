#include <fstream>
#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

int main() {
    std::ifstream infile("bag.txt");
    if (!infile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    int sumOfPossibleGames = 0;

    while (std::getline(infile, line))
    {
        std::vector<int> PosNum;
        auto LastPosGameId = line.find(": "); //position der letzte Zah der id
        auto FirstPosGameId = line.find("Game ");
        std::string IdStr = line.substr(FirstPosGameId+5, LastPosGameId-FirstPosGameId-5);
        int Id = std::stoi(IdStr);
        auto LastFirPosNum = std::find_if(line.begin()+LastPosGameId, line.end(), isalnum);
        auto LastFirPos = std::distance(line.begin(), LastFirPosNum);
        std::string firstNumStr = line.substr(LastPosGameId+1, LastFirPos-LastPosGameId+2);
        int Numnum = std::stoi(firstNumStr);
        std::cout<<"Numnum"<< Numnum << '\n';
        //std::cout << "LastFirPosNum: "<<LastFirPos<<" LastPosGameId: "<<LastPosGameId<< "firstNumStr"<< firstNumStr <<'\n';
        for (int i = LastPosGameId; i < line.length(); ++i)
        {
            if (line[i] == ';')
            {
                PosNum.push_back(i);
            }
             else if (line[i] == ',')
            {
                PosNum.push_back(i);
            }
        }
        std::cout<<"Id: " << Id <<'\n';
        for (int FirstPos : PosNum )
        {
            
            std::cout << "Zeichen " << line[FirstPos] << " ist an " << FirstPos << std::endl;
        }
    }
    return 0;
}

