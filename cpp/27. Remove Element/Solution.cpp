#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int size = nums.size();

        int uniqueIndex = 0;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] != val)
            {
                nums[uniqueIndex] = nums[i];
                uniqueIndex++;
            }
        }

        return uniqueIndex;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int res = s->removeElement(nums, 2);
    for (int i = 0; i < res; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << res << endl;
}