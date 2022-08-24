#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#define INPUT_DIRECTION split_line[0]
#define INPUT_VALUE split_line[1];

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> elems;
    std::string word = "";
 
    for (auto it = str.cbegin(); it != str.cend(); it++) {

        if (*it == delim) {

            elems.push_back(word);
            word = "";
            continue;
        }

        word += *it;
    }

    if (!word.empty()) {
        elems.push_back(word);
    }

    return elems;
}
int main(){
    
    std::fstream input("input.txt");
    std::string line;

    int depth = 0;
    int horizontal = 0;

    std::vector<std::string> split_line;
    while (std::getline(input, line)) {
        
        split_line = split(line, ' ');
        int input_value = std::stoi(split_line[1]);

        if (INPUT_DIRECTION == "forward") {

            horizontal += input_value;

        }

        else if (INPUT_DIRECTION == "down") {
            depth += input_value;

        }
        
        else if (INPUT_DIRECTION == "up") {
            depth -= input_value;

        }
    }
    
    std::cout << "Horizontal: " << horizontal << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    std::cout << horizontal*depth << std::endl;

    int stop = 0;
    std::cin >> stop;
}