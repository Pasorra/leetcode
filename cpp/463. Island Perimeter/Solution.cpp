#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;
        for (size_t y = 0; y < grid.size(); y++)
        {
            for (size_t x = 0; x < grid[0].size(); x++)
            {
                if (grid[y][x] == 0)
                {
                    continue;
                }
                res += check(x - 1, y, grid);
                res += check(x + 1, y, grid);
                res += check(x, y - 1, grid);
                res += check(x, y + 1, grid);
            }
        }
        return res;
    }
    int check(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size())
        {
            return 1;
        }
        return grid[y][x] == 0;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> v = {
        {1, 1},
    };
    int res = s->islandPerimeter(v);
    cout << res << endl;
    return 0;
}