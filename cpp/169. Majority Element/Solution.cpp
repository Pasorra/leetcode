#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int goal = nums.size() / 2;
        for (int num : nums)
        {
            map[num]++;
            if (map[num] > goal)
            {
                return num;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 1, 1, 2};
    int res = s->majorityElement(nums);
    cout << res << endl;
}