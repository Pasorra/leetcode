#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        double p = pow(26, columnTitle.size() - 1);
        for (int i = 0; i < columnTitle.size(); i++)
        {
            result += (columnTitle[i] - 64) * p;
            p /= 26;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->titleToNumber("FXSHRXW");
    cout << res << endl;
}