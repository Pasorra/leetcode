#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int result = start;
        start += 2;
        for (int i = 0; i < n - 1; i++)
        {
            result ^= start;
            start += 2;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int result = s->xorOperation(4, 3);
    cout << "Result: " << result << endl;
    return 0;
}