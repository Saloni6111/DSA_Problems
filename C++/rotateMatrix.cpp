#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> ans = matrix;

    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ans[j][size - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}

int main()
{
    // Your code here

    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}