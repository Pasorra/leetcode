#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        while (n > 1)
        {
            if (n % 3 != 0)
            {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->isPowerOfThree(27);
    cout << res << endl;
}