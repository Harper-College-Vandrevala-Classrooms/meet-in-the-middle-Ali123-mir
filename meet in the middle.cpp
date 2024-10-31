#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

double calculateMedian(const std::vector<int>& numbers) {
    size_t size = numbers.size();
    if (size % 2 == 1) {
        return numbers[size / 2];
    } else {
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    }
}

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }

    std::vector<int> numbers;
    std::string line, number;

    if (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, number, ',')) {
            numbers.push_back(std::stoi(number));
        }
    }
    file.close();

    if (numbers.empty()) {
        std::cerr << "Error: No data found in file.\n";
        return 1;
    }

    double median = calculateMedian(numbers);
    std::cout << "The median of the dataset is " << median << "\n";

    return 0;
}