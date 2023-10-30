#include <vector>
#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<int> visitedMin(n, INT32_MAX);
        vector<int> visitedPairs(n);
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int res = abs(x1 - x2) + abs(y1 - y2);
                if (res < visitedMin[i])
                {
                    visitedMin[i] = res;
                    visitedPairs[i] = j;
                }
                if (res < visitedMin[j])
                {
                    visitedMin[j] = res;
                    visitedPairs[j] = i;
                }
            }
        }
        unordered_set<string> set;
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << visitedPairs[i] << " = " << visitedMin[i] << endl;
            string s = to_string(min(i, visitedPairs[i])) + to_string(max(i, visitedPairs[i]));
            if (set.find(s) == set.end())
            {
                set.insert(s);
                result += visitedMin[i];
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
