#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point {
    int value;
    string key;
};

int main(int argc, char const *argv[])
{
    int num_of_rows;
    vector<vector<int>> rows;
    std::cin >> num_of_rows;
    cout << "test\n";
    for (int i = 1; i <= num_of_rows; i++)
    {
        vector<int> row;
        for (int j = 0; j < i; j++)
        {
            int value;
            std::cin >> value;
            row.push_back(value);
        }
        rows.push_back(row);
    }
    cout << "test\n";
    vector<vector<int>> ans;
    for (int i = 0; i < num_of_rows;++i) {
        vector<int> tmp;
        for (int j = 0; j < i+1; ++j) {
            tmp.push_back(0);
        }
        ans.push_back(tmp);
        cout << i << " test\n";

    }

    ans[0][0] = rows[0][0];
    cout << "test\n";
    for (int row_index = 1; row_index < num_of_rows; row_index++)
    {
        auto row = rows[row_index];
        for (int col_index = 0; col_index < row_index; col_index++)
        {
            if (col_index == 0) {
                ans[row_index][col_index] = ans[row_index-1][0] + rows[row_index][col_index];
            }
            else if (col_index == row_index-1) {
                ans[row_index][col_index] = ans[row_index-1][row_index-2] + rows[row_index][col_index];
            }
            else {
                ans[row_index][col_index] = max(ans[row_index-1][col_index-1],ans[row_index-1][col_index]) + rows[row_index][col_index];
            }
        }
        
    }
    cout << "test\n";
    int out = 0;
    for (int i = 0; i < ans[num_of_rows-1].size();++i) {
        out = max(out, ans[num_of_rows-1][i]);
    }
    cout << out << "\n";

    return 0;
}
