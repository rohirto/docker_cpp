#include <iostream>
#include <vector>

int main() {
    // Define a 3x3 grid represented by a 3D vector of characters
    std::vector<std::vector<std::vector<char>>> grid(3, std::vector<std::vector<char>>(3, std::vector<char>(1, ' ')));

    // Create a vector<char> to copy into the grid
    std::vector<char> charVector = {'A', 'B', 'C'};

    // Specify the location (i, j) where you want to copy the vector
    int i = 1; // Row index
    int j = 2; // Column index

    // Copy the charVector into the specified location
    grid[i][j] = charVector;

    // Print the updated grid
    for (const auto& row : grid) {
        for (const auto& col : row) {
            for (char ch : col) {
                std::cout << ch << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
