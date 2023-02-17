#include <fstream>
#include <string>
#include <iostream>

std::string split(std::string& str, const std::string& delimiter) {
	std::string token = str.substr(0, str.find(delimiter));
	str.erase(0, str.find(delimiter) + delimiter.length());
	return token;
}

// for day 2 - part 1
bool parseLine1(std::string line) {
	int min = std::stoi(split(line, "-"));
	int max = std::stoi(split(line, " "));
	char token = split(line, ": ").at(0);
	int tokenCount = 0;
	for (auto it : line) {
		if (it == token) {
			++tokenCount;
		}
	}
	std::cout << "min=" << min << std::endl;
	std::cout << "max=" << max << std::endl;
	std::cout << "token=" << token << std::endl;
	std::cout << "tokenCount=" << tokenCount << std::endl;

	return (tokenCount >= min && tokenCount <= max);
}

// for day 2 - part 2
bool parseLine2(std::string line) {
	int pos1 = std::stoi(split(line, "-"));
	int pos2 = std::stoi(split(line, " "));
	char token = split(line, ": ").at(0);
	int tokenCount = 0;
	if (line.at(pos1 - 1) == token)
		++tokenCount;
	if (line.at(pos2 - 1) == token)
		++tokenCount;
	std::cout << "tokenCount=" << tokenCount << std::endl;
	return tokenCount == 1;
}

int main() {
	std::ifstream infile("data.txt");
	std::string line;
	int validPasswords = 0;
	while (std::getline(infile, line)) {
		std::cout << line << std::endl;
		if (parseLine2(line))
			++validPasswords;
	}
	std::cout << validPasswords << std::endl;
}