#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <bitset>
#include <cstddef>

#define LOG(x) std::cout << x << std::endl

int flipBits2(int n, int k) { //Shamelessly stolen from Bernhard Barker on stackoverflow
	int mask = (1 << k) - 1;
	return ~n & mask;
}

int main() {
	const int LINE_LENGTH = 12;
	
	std::vector<int> bit_sums(LINE_LENGTH);
	std::fstream input("input.txt");
	std::string line = "";

	unsigned int gamma_rate = 0; //Uses most common bit per column
	unsigned int epsilon_rate = 0; //Inverted bits of above ^

	std::string bit_holder = "";

	while (std::getline(input, line)) {
		for (auto it = line.begin(); it != line.end(); it++)
		{

			if (*it == '1') {

				bit_sums[std::distance(line.begin(), it)]++;
			}
			else {

				bit_sums[std::distance(line.begin(), it)]--;
			}
		}

	}

	std::for_each(bit_sums.begin(), bit_sums.end(), [&](const int i) { 
		if (i > 1) {
			bit_holder += '1';
		}

		else {
			bit_holder += '0';
		}
	});

	LOG(bit_holder);
	gamma_rate = std::stoi(bit_holder, 0, 2);
	epsilon_rate = flipBits2(gamma_rate, LINE_LENGTH);
	LOG(gamma_rate);
	LOG(epsilon_rate);
	LOG(gamma_rate * epsilon_rate);
	std::cin.get();

}