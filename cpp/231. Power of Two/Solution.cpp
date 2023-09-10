#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        while (n > 2)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return n > 0;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isPowerOfTwo(2);
    cout << res << endl;
    return 0;
}