
#include <iostream>
#include <fstream>
#include <string>

void printHead(const std::string& filename, int numLines) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        int count = 0;
        while (std::getline(file, line) && count < numLines) {
            std::cout << line << std::endl;
            count++;
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: ./head <filename> <num_lines>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    int numLines = std::stoi(argv[2]);

    printHead(filename, numLines);

    return 0;
}
