#include <iostream>
#include <string>
#include <fstream>
#include <list>


std::ifstream infile("data.txt");

bool numbersAreValid(int n1, int n2, int n3) {
	return (n1 + n2 + n3 == 2020);
}

int main()
{
	std::list<int> numbers;
	std::string line;
	while (std::getline(infile, line)) {
		numbers.push_back(std::stoi(line));
	}
	for (auto it1 = numbers.cbegin(); it1 != numbers.cend(); ++it1) {
		for (auto it2 = it1; it2 != numbers.cend(); ++it2) {
			for (auto it3 = it2; it3 != numbers.cend(); ++it3) {
				if (numbersAreValid(*it1, *it2, *it3)) {
					std::cout << *it1 << std::endl;
					std::cout << *it2 << std::endl;
					std::cout << *it3 << std::endl;
					std::cout << *it1 * *it2 * *it3 << std::endl;
				}
			}

			
		}
	}

	return 0;
}

