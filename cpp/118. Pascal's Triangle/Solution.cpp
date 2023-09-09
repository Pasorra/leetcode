#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result = {};
        for (int row = 1; row <= numRows; row++)
        {
            vector<int> subResult;
            for (int col = 1; col <= row; col++)
            {
                if (col == 1 || col == row)
                {
                    subResult.push_back(1);
                }
                else
                {
                    subResult.push_back(result[row - 2][col - 2] + result[row - 2][col - 1]);
                }
            }
            result.push_back(subResult);
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> res = s->generate(30);
    cout << "[";

    for (const vector<int> &row : res)
    {
        cout << "[";

        for (int i = 0; i < row.size(); i++)
        {
            cout << row[i];

            if (i < row.size() - 1)
            {
                cout << ",";
            }
        }

        cout << "]";

        if (&row != &res.back())
        {
            cout << ",";
        }
    }

    cout << "]" << endl;
}