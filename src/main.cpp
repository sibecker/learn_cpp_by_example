#include "learn.h"

#include <ranges>
#include <string>

using namespace std::string_literals;

void show_view(std::ostream& stream, std::vector<std::vector<int>> const& triangle)
{
    if (!triangle.empty()) {
        std::string spaces(triangle.back().size(), ' ');
        for (auto const& row: triangle) {
            if (!spaces.empty())
                spaces.resize(spaces.size() - 1);
            stream << spaces;
            auto const odds = row | std::views::transform([](int x){
                return x % 2 ? '*' : ' ';
            });
            for(auto const data : odds) {
                stream << data << ' ';
            }
            stream << '\n';
        }
    }
}

int main()
{
    show_view(std::cout, generate_triangle(34))
}
