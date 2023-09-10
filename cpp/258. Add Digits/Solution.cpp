#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int result = 0;
            while (num > 0)
            {
                result += num % 10;
                num /= 10;
            }
            num = result;
        }
        return num;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->addDigits(38);
    cout << res << endl;
    return 0;
}