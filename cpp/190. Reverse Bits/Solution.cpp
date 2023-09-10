#include <iostream>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        uint32_t p = 1 << 31;
        while (n > 0)
        {
            result += p * (n % 2);
            n /= 2;
            p >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    uint32_t res = s->reverseBits(43261596);
    cout << res << endl;
}