#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
        {
            if (set.find(num) != set.end())
            {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 2, 3};
    bool res = s->containsDuplicate(nums);
    cout << res << endl;
}