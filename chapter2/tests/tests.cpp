#include "catch2/catch_test_macros.hpp"

#include "triangle.h"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <string>


using namespace std::string_literals;

template<typename T>
std::string to_string(T const& x)
{
    std::ostringstream oss;
    oss << x;
    return oss.str();
}

TEST_CASE("Chapter 2 - Pascal's triangle")
{
    SECTION("get_next_row")
    {
        CHECK(get_next_row({}) == std::vector{1});
        CHECK(get_next_row({1}) == std::vector{1, 1});
        CHECK(get_next_row({1, 1}) == std::vector{1, 2, 1});
        CHECK(get_next_row({1, 4, 6, 4, 1}) == std::vector{1, 5, 10, 10, 5, 1});
    }

    SECTION("generate_triangle")
    {
        CHECK(generate_triangle(0) == std::vector<std::vector<int>>{});
        CHECK(generate_triangle(1) == std::vector<std::vector<int>>{{1}});
        CHECK(generate_triangle(2) == std::vector<std::vector<int>>{{1}, {1, 1}});
        CHECK(generate_triangle(6) == std::vector<std::vector<int>>{
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
            {1, 5, 10, 10, 5, 1},
        });
    }

    SECTION("operator<<")
    {
        CHECK(to_string(generate_triangle(0)) == ""s);
        CHECK(to_string(generate_triangle(1)) == "     1   \n"s);
        CHECK(to_string(generate_triangle(2)) == "        1   \n     1     1   \n"s);
        CHECK(to_string(generate_triangle(4)) == "              1   \n           1     1   \n        1     2     1   \n     1     3     3     1   \n"s);
    }

    SECTION("check_properties")
    {
        // Had to write these as lambdas in order to have them local.
        // pLeased to see that CHECK works in them!
        auto const is_palindrome = [](std::vector<int> const& row)
        {
            auto const forward = row | std::views::take(row.size() / 2);
            auto const backward = row | std::views::reverse | std::views::take(row.size() / 2);
            return std::ranges::equal(forward, backward);
        };

        auto const check_properties = [=](std::vector<std::vector<int>> const& triangle)
        {
            size_t row_number = 0;
            size_t expected_total = 1;
            for (const auto& row: triangle) {
                CHECK(row.front() == 1);
                CHECK(row.back() == 1);
                CHECK(row.size() == ++row_number);

                using std::begin;
                using std::end;
                CHECK(std::accumulate(begin(row), end(row), size_t{0}) == expected_total);
                expected_total *= 2;

                auto const negative = [](int x){ return x < 0; };
                auto negatives = row | std::views::filter(negative);
                CHECK(negatives.empty());

                CHECK(is_palindrome(row));
            }
        };

        check_properties(generate_triangle(0));
        check_properties(generate_triangle(1));
        check_properties(generate_triangle(34));
    }
}