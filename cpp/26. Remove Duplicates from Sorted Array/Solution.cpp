#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();

        int uniqueIndex = 0;

        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[uniqueIndex])
            {
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }

        return uniqueIndex + 1;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {};
    int res = s->removeDuplicates(nums);
    cout << res << endl;
    for (int val : nums)
    {
        cout << val << ", ";
    }
    cout << endl;
    return 0;
}