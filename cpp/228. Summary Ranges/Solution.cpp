#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int size = nums.size();
        vector<string> result;

        if (size == 0)
        {
            return result;
        }

        int startingIndex = 0;
        string newStr;

        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] + 1 != nums[i + 1])
            {
                if (i != startingIndex)
                {
                    newStr = to_string(nums[startingIndex]) + "->" + to_string(nums[i]);
                }
                else
                {
                    newStr = to_string(nums[startingIndex]);
                }
                result.push_back(newStr);
                startingIndex = i + 1;
            }
        }
        if (startingIndex == size - 1)
        {
            newStr = to_string(nums[startingIndex]);
        }
        else
        {
            newStr = to_string(nums[startingIndex]) + "->" + to_string(nums[size - 1]);
        }
        result.push_back(newStr);
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = s->summaryRanges(nums);
    for (string s : res)
    {
        cout << s << ", ";
    }
    cout << endl;
    return 0;
}