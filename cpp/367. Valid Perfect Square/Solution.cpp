#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        return fmod(sqrt(num), 1) == 0;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isPerfectSquare(25);
    cout << res << endl;
    return 0;
}