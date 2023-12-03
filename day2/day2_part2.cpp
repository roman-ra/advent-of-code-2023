#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <regex>


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ifstream input("input.txt");
    std::string line;

    uint64_t sum{0};

    std::regex shows_regex("([0-9]+) (red|green|blue)", std::regex_constants::ECMAScript | std::regex_constants::icase);

    while (std::getline(input, line)) {
        if (line.length() < 1) { continue; }

        uint64_t max_red   {0};
        uint64_t max_green {0};
        uint64_t max_blue  {0};

        auto shows = std::sregex_iterator(line.begin(), line.end(), shows_regex);

        for (auto i = shows; i != std::sregex_iterator(); ++i) {
            auto sub = i->begin(); sub++;
            std::string num_str = sub->str(); sub++;
            std::string color_str = sub->str();
            uint64_t num = std::atoll(num_str.c_str());
            switch (color_str[0])
            {
            case 'r':
                if (num > max_red)   { max_red = num; } break;
            case 'g':
                if (num > max_green) { max_green = num; } break;
            case 'b':
                if (num > max_blue)  { max_blue = num; } break;
            default:
                break;
            }
        }

        sum += max_red * max_green * max_blue;
    }

    input.close();
   
    std::cout << sum << std::endl;
    
    return 0;
}
