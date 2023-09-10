#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n > 0)
        {
            if (n % 2)
            {
                result++;
            }
            n /= 2;
        }
        return result;
    }
};
int main()
{
    Solution *s = new Solution();
    uint32_t res = s->hammingWeight(2);
    cout << res << endl;
}