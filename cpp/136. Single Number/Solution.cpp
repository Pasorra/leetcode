#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        for (auto val : map)
        {
            if (val.second == 1)
            {
                return val.first;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 1, 2, 2, 3};
    int res = s->singleNumber(nums);
    cout << res << endl;
}