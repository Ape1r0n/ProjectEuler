#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream in("names.txt");
    std::string line;
    std::vector<std::string> names;

    if(in.is_open()){
        std::getline(in, line, ',');
        while(in){
            line.erase(std::remove(line.begin(), line.end(), '\"'), line.end());
            names.push_back(line);
            std::getline(in, line, ',');
        }
        in.close();
    }else{
        std::cerr << "Error: unable to open file." << std::endl;
        return 1;
    }

    std::sort(names.begin(), names.end());

    long long name_score = 0;
    for(int i = 0; i < names.size(); ++i) {
        int score = 0;
        for (char c : names[i]) score += c - 'A' + 1; 
        name_score += score * (i + 1);
    }

    std::cout << name_score << '\n';
    return 0;
}

