#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int i = 0;
        while (true)
        {
            unsigned long long int val = static_cast<unsigned long long int>(i) * i;
            if (x < val)
            {
                return i - 1;
            }
            else if (x == val)
            {
                return i;
            }
            i++;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->mySqrt(2147483647);
    cout << res << endl;
}