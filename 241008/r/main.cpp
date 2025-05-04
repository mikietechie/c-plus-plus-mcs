#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

enum SolutionType
{
    UNIQUE,
    INFINITE,
    IMPOSSIBLE
};

pair<SolutionType, vector<double>> solve_system(vector<vector<double>> matrix)
{
    int n = matrix.size();
    vector<double> solution(n);

    // Gaussian elimination with partial pivoting
    for (int col = 0; col < n; ++col)
    {
        // Partial pivoting - find row with maximum element in current column
        int max_row = col;
        for (int row = col + 1; row < n; ++row)
        {
            if (abs(matrix[row][col]) > abs(matrix[max_row][col]))
            {
                max_row = row;
            }
        }

        // Swap rows if needed
        if (max_row != col)
        {
            swap(matrix[col], matrix[max_row]);
        }

        // If pivot is zero, matrix is singular
        if (abs(matrix[col][col]) < EPS)
        {
            continue;
        }

        // Eliminate current column in lower rows
        for (int row = col + 1; row < n; ++row)
        {
            double factor = matrix[row][col] / matrix[col][col];
            for (int c = col; c <= n; ++c)
            {
                matrix[row][c] -= factor * matrix[col][c];
            }
        }
    }

    // Check for no solution or infinite solutions
    for (int row = 0; row < n; ++row)
    {
        bool all_zero = true;
        for (int col = 0; col < n; ++col)
        {
            if (abs(matrix[row][col]) > EPS)
            {
                all_zero = false;
                break;
            }
        }
        if (all_zero)
        {
            if (abs(matrix[row][n]) > EPS)
            {
                return {IMPOSSIBLE, {}}; // No solution
            }
            else
            {
                return {INFINITE, {}}; // Infinite solutions
            }
        }
    }

    // Back substitution
    for (int row = n - 1; row >= 0; --row)
    {
        solution[row] = matrix[row][n];
        for (int col = row + 1; col < n; ++col)
        {
            solution[row] -= matrix[row][col] * solution[col];
        }
        solution[row] /= matrix[row][row];

        if (isnan(solution[row]))
        {
            return {IMPOSSIBLE, {}};
        }
    }

    return {UNIQUE, solution};
}

int main()
{
    int n;
    std::cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    auto [type, solution] = solve_system(matrix);

    std::cout << fixed << setprecision(3);
    switch (type)
    {
    case UNIQUE:
        std::cout << "single\n";
        for (double x : solution)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
        break;
    case INFINITE:
        std::cout << "infinity\n";
        break;
    case IMPOSSIBLE:
        std::cout << "impossible\n";
        break;
    }

    return 0;
}