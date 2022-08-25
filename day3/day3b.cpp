#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <bitset>
#include <cstddef>

#define LOG(x) std::cout << x << '\n'

int flipBits(int n, int k) { //Shamelessly stolen from Bernhard Barker on stackoverflow
	int mask = (1 << k) - 1;
	return ~n & mask;
}

int main() {
	const int LINE_LENGTH = 12;
	
	std::vector<int> bit_sums(LINE_LENGTH);
	std::fstream input("input.txt");
	std::string line;

	std::vector<std::string> input_vec;
	std::vector<std::string>::iterator iter;
	while (std::getline(input, line)) {
		input_vec.push_back(line);
	}

	for (int line_index = 0; line_index < LINE_LENGTH; line_index++) {

		char bit_to_remove = '0';
		int bit_counter = 0;

		std::for_each(input_vec.begin(), input_vec.end(), [&](std::string line ) {

			if (line[line_index] == '1') {
				bit_counter++;
				
			}
			else if (line[line_index == '0']) {
				bit_counter--;
				
			}
		});

		if (bit_counter < 0) {

			
			bit_to_remove = '1';
		}

		LOG("Bit counter is");
		LOG(bit_counter);

		for (std::string line : input_vec) {
			if (line[line_index] == bit_to_remove) {
				input_vec.erase(std::remove(input_vec.begin(), input_vec.end(), line));
			}
		}
		//for (iter = input_vec.begin(); iter != input_vec.end(); iter++)
		//{
		//	std::string temp = *iter;
		//	if (temp[line_index] == bit_to_remove) {
		//		input_vec.erase(iter);
		//		
		//	}

		//}
		LOG("Vector new size:");
		LOG(input_vec.size());
		if (input_vec.size() == 1) {
			LOG(input_vec[0]);
			break;
		}

	}
	LOG("Done!");
	std::cin.get();
	
}