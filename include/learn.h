#pragma once

#include <iostream>
#include <vector>

std::vector<int> get_next_row(std::vector<int> const& last_row);

std::vector<std::vector<int>> generate_triangle(int rows);

std::ostream& operator<<(std::ostream& stream, std::vector<std::vector<int>> const& triangle);
