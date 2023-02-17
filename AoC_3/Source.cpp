#include <fstream>
#include <string>
#include <iostream>
#include <vector>

std::vector<std::vector<char>> terrain;
int d_x = 7;
int d_y = 1;


bool hasTreeAt(const int x, const int y) {
	int wrapped_x = x % terrain[1].size();
	return (terrain[y][wrapped_x] == '#');
}

int main() {
	std::ifstream ifstream("data.txt");
	std::string line;
	
	int lineNumber = 0;
	while (std::getline(ifstream, line)) {
		std::cout << line << std::endl;
		terrain.push_back(std::vector<char>());
		for (char c : line) {
			terrain[lineNumber].push_back(c);
		}
		++lineNumber;
	}

	int x = 0;
	int trees_hit = 0;
	for (int y = 0; y < terrain.size(); y+= d_y) {
		if (hasTreeAt(x, y)) {
			++trees_hit;
			std::cout << "tree at " << x << "/" << y << std::endl;
		}
		else {
			std::cout << "no tree at" << x << "/" << y << std::endl;
		}
		x += d_x;
	}
	std::cout << trees_hit << std::endl;
}