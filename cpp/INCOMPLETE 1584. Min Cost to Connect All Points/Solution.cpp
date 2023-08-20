#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int result = 0;
        for (int x = 0; x < n; x++)
        {
            int smallest = INT32_MAX;
            int smallest_index = 0;
            for (int y = 0; y < n; y++)
            {
                if (x == y)
                {
                    continue;
                }
                int res = abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
                if (res < smallest)
                {
                    smallest_index = y;
                    smallest = res;
                }
            }
            cout << smallest << endl;
            try
            {
                if (points[x][2] == smallest_index)
                {
                    continue;
                }
                else
                {
                    result += smallest;
                    points[smallest_index][2] = x;
                }
            }
            catch (const std::exception &e)
            {
                result += smallest;
                points[smallest_index][2] = x;
            }
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> points = {{0, 0},
                                  {2, 2},
                                  {3, 10},
                                  {5, 2},
                                  {7, 0}};
    int result = s->minCostConnectPoints(points);
    cout << "Result: " << result << endl;
    return 0;
}
