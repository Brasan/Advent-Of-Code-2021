#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

#define LOG(x) std::cout << x << '\n'

using std::vector;

const int BOARD_HEIGHT = 5;
const int BOARD_WIDTH = 5;

bool check_for_win(){
	return 1;
}

class Board {
public:
	vector<vector<std::pair<int, bool>>> height;
		
};

int main() {

	vector<int> nums_to_draw{};
	vector<Board> boards{};

	std::fstream input("input.txt");
	std::string line;
	bool past_first_line = false;
	std::string token;
	int rows_in_current_board{0};
	Board* current_board;




	while (std::getline(input, line)) {
		std::cout << "beginning" << '\n';
		std::stringstream ss{line};

		if (rows_in_current_board == 0) { current_board = new Board;}

		if (line.length() == 0) { std::cout << "skipping empty line" << '\n'; continue; }

		if (!past_first_line) {

			while (std::getline(ss, token, ',')) {

				nums_to_draw.push_back(stoi(token));
			}
			
			past_first_line = true;
			continue;
		}

		if (rows_in_current_board < BOARD_HEIGHT) {

			vector<std::pair<int, bool>> current_row{};
			
			while (std::getline(ss, token, ' ')) {
				std::pair<int, bool> pair_to_add(stoi(token), false);
				current_row.push_back(pair_to_add);
			}

			std::cout << "doing row stuff" << '\n';
			current_board->height.push_back(current_row);
			++rows_in_current_board;
			continue;
		}
		std::cout << "pushing back" << '\n';
		boards.push_back(*current_board);
		delete current_board;
		rows_in_current_board = 0;
	}
	
	std::cout << nums_to_draw.size() << '\n';
	std::cout << boards.size() << '\n';
	std::cin.get();
	return 1;
}