#include "learn.h"

#include <format>

std::vector<int> get_next_row(std::vector<int> const& last_row)
{
    std::vector next_row{1};
    if (!last_row.empty()) {
        for (size_t idx = 0; idx + 1 < last_row.size(); ++idx) {
            next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
        }
        next_row.emplace_back(1);
    }
    return next_row;
}

std::vector<std::vector<int>> generate_triangle(int rows)
{
    std::vector<std::vector<int>> triangle{};
    if(rows > 0)
        triangle.push_back(get_next_row({}));

    for (int row = 1; row < rows; ++row) {
        triangle.push_back(get_next_row(triangle.back()));
    }
    return triangle;
}

std::ostream& operator<<(std::ostream& stream, std::vector<std::vector<int>> const& triangle)
{
    if (!triangle.empty()) {
        auto const final_row_size = triangle.back().size();
        std::string spaces(final_row_size * 3, ' ');
        for (auto const& row: triangle) {
            stream << spaces;
            if (spaces.size() > 3)
                spaces.resize(spaces.size()-3);
            for(auto const data : row) {
                stream << std::format("{: ^{}}", data, 6);
            }
            stream << '\n';
        }
    }
    return stream;
}
