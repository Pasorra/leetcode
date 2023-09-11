#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return;
        }
        int left = 0;
        int right = 1;
        while (right < size && left < size)
        {
            if (nums[left] == 0)
            {
                while (nums[right] == 0)
                {
                    right++;
                    if (right == size)
                    {
                        return;
                    }
                }
                swap(nums[left], nums[right]);
            }
            left++;
            right++;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    s->moveZeroes(nums);
    for (int num : nums)
    {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}