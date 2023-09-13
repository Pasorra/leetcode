#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
public:
    vector<int> &nums;
    NumArray(vector<int> &nums) : nums(nums) {}

    int sumRange(int left, int right)
    {
        int result = 0;
        for (; left <= right; left++)
        {
            result += nums[left];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    NumArray *s = new NumArray(nums);
    int res = s->sumRange(0, 5);
    cout << res << endl;
    return 0;
}