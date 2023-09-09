#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result = {};
        for (int row = 1; row < rowIndex + 2; row++)
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
                    subResult.push_back(result[col - 2] + result[col - 1]);
                }
            }
            result = subResult;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> res = s->getRow(3);
    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];

        if (i < res.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]";
}