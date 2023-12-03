#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <regex>

#define NUM_RED_CUBES   12
#define NUM_GREEN_CUBES 13
#define NUM_BLUE_CUBES  14


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ifstream input("input_part1.txt");
    std::string line;

    uint64_t sum{0};

    std::regex shows_regex("([0-9]+) (red|green|blue)", std::regex_constants::ECMAScript | std::regex_constants::icase);

    while (std::getline(input, line)) {
        if (line.length() < 1) { continue; }
        
        size_t game_id_end = line.find(':');
        uint64_t game_id = std::atoll(line.substr(5, game_id_end - 5).c_str());

        bool game_is_possible = true;

        auto shows = std::sregex_iterator(line.begin(), line.end(), shows_regex);

        for (auto i = shows; i != std::sregex_iterator(); ++i) {
            auto sub = i->begin(); sub++;
            std::string num_str = sub->str(); sub++;
            std::string color_str = sub->str();
            uint64_t num = std::atoll(num_str.c_str());
            switch (color_str[0])
            {
            case 'r':
                game_is_possible &= (num <= NUM_RED_CUBES); break;
            case 'g':
                game_is_possible &= (num <= NUM_GREEN_CUBES); break;
            case 'b':
                game_is_possible &= (num <= NUM_BLUE_CUBES); break;
            default:
                break;
            }
        }

        if (game_is_possible) {
            sum += game_id;
        }
    }

    input.close();
   
    std::cout << sum << std::endl;
    
    return 0;
}
