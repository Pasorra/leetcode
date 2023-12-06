#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int *arr[3] = {nullptr, nullptr, nullptr};
        unsigned int uniqueEleCount = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (arr[x] == nullptr)
                {
                    uniqueEleCount++;
                    arr[x] = new int(nums[i]);
                    break;
                }
                else if (nums[i] > *arr[x])
                {
                    swap(nums[i], *arr[x]);
                }
                else if (nums[i] == *arr[x])
                {
                    break;
                }
            }
        }
        if (uniqueEleCount >= 3)
        {
            return *arr[2];
        }
        return *arr[0];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> i = {3, 2, 1};
    int res = s->thirdMax(i);
    cout << res << endl;
    return 0;
}