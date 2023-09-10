#include <iostream>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else if (n % 3 == 0)
            {
                n /= 3;
            }
            else if (n % 5 == 0)
            {
                n /= 5;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isUgly(10);
    cout << res << endl;
    return 0;
}