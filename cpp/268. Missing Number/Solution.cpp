#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // at first I solved it like this because I thought it would overflow
    //  int missingNumber(vector<int> &nums)
    //  {
    //      sort(nums.begin(), nums.end());
    //      int size = nums.size();
    //      if (nums[0] != 0)
    //      {
    //          return 0;
    //      }
    //      else if (nums[size - 1] != size)
    //      {
    //          return size;
    //      }
    //      for (int i = 0; i < size; i++)
    //      {
    //          if (nums[i] + 1 != nums[i + 1])
    //          {
    //              return nums[i] + 1;
    //          }
    //      }
    //      return 0;
    //  }
    int missingNumber(vector<int> &nums)
    {
        int size = nums.size();
        int sum = (size * (size + 1)) / 2;
        int arrSum = 0;
        for (int num : nums)
        {
            arrSum += num;
        }
        return sum - arrSum;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {0, 1, 3};
    int res = s->missingNumber(nums);
    cout << res << endl;
    return 0;
}