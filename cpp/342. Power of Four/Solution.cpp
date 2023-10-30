#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 4 != 0)
            {
                return false;
            }
            n /= 4;
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isPowerOfFour(16);
    cout << res << endl;
    return 0;
}