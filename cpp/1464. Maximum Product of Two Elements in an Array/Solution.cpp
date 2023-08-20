#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max = 0;
        int secondaryMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            if (val > max)
            {
                secondaryMax = max;
                max = val;
            }
            else if (val > secondaryMax)
            {
                secondaryMax = val;
            }
        }
        return (max - 1) * (secondaryMax - 1);
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> points = {3, 4, 5, 2};
    int result = s->maxProduct(points);
    cout << "Result: " << result << endl;
    return 0;
}
