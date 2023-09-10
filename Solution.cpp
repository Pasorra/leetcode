#include <iostream>
using namespace std;

class Solution
{
public:
    bool boilerplate()
    {
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->boilerplate();
    cout << res << endl;
    return 0;
}