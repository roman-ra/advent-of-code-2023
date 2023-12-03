#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ifstream input("input_part1.txt");
    std::string line;

    char first{'0'}, last{'0'};
    bool first_found{false};
    uint64_t sum{0};

    while (std::getline(input, line)) {
        if (line.length() < 1) { continue; }
        
        for (char c: line) {
            if (c < '0' || c > '9') { continue; }
            if (!first_found) {
                first = c;
                first_found = true;
            }
            last = c;
        }
        sum += (first - '0') * 10 + (last - '0');
        first_found = false;
    }

    input.close();
   
    std::cout << sum << std::endl;
    
    return 0;
}
