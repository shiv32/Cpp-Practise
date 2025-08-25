#include <iostream>
#include <vector>

void matrix_1()
{
    std::cout << __PRETTY_FUNCTION__ << "\n";

    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (const auto &row : matrix) // iterate over each inner vector
    {
        for (const auto &val : row) // iterate over each element
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

void matrix_2()
{
    std::cout << __PRETTY_FUNCTION__ << "\n";

    // Create a 2D vector
    std::vector<std::vector<int>> matrix;

    // Insert data dynamically
    matrix.push_back({1, 2, 3});    // first row
    matrix.push_back({4, 5});       // second row (jagged row with fewer elements)
    matrix.push_back({6, 7, 8, 9}); // third row (longer row)

    // Add one element to an existing row
    matrix[1].push_back(6); // Now second row: {4,5,6}

    // Iterate using range-based loop (recommended)
    std::cout << "Using range-based loop:\n";
    for (const auto &row : matrix)
    {
        for (const auto &val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    matrix_1();

    matrix_2();

    return 0;
}
