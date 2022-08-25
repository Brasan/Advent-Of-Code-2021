#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#define LOG(x) std::cout << x << '\n'

bool check_for_win(){}

int main() {

	using std::vector;

	vector<int> nums_to_draw{1,2,3,4,5,6,7};

	std::transform(nums_to_draw.begin(), nums_to_draw.end(), nums_to_draw, [](int i) {
		return i *= 100;
		});

	std::for_each(nums_to_draw.begin(), nums_to_draw.end(), [](int i) { std::cout << i << '\n'; });
	std::fstream input("input.txt");
	std::string line;
	bool past_first_line = false;

	std::string token;
	
	while (std::getline(input, line)) {

		if (!past_first_line) {

			std::stringstream ss(line);

			while (std::getline(ss, token, ',')) {

				nums_to_draw.push_back(std::stoi(token));
			}
			
			past_first_line == true;
		}
	}
}