#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (true)
        {
            if (set.find(n) != set.end())
            {
                return false;
            }
            set.insert(n);
            int res = 0;
            while (n > 0)
            {
                int a = n % 10;
                res += a * a;
                n /= 10;
            }
            if (res == 1)
            {
                return true;
            }
            n = res;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isHappy(19);
    cout << res << endl;
}