#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int product = 1;
        int sum = 0;
        while (n > 0)
        {
            int val = n % 10;
            n /= 10;
            product *= val;
            sum += val;
        }
        return product - sum;
    }
};

int main()
{
    Solution *s = new Solution();
    int result = s->subtractProductAndSum(234);
    cout << "Result: " << result << endl;
    return 0;
}