#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return false;
        }
        queue<int> q;
        unordered_set<int> set;
        for (int val : nums)
        {
            if (set.find(val) != set.end())
            {
                return true;
            }
            if (k == 0)
            {
                int qVal = q.front();
                set.erase(qVal);
                q.pop();
            }
            else
            {
                k--;
            }
            q.push(val);
            set.insert(val);
        }

        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 2, 3, 4, 5, 6, 5};
    bool res = s->containsNearbyDuplicate(nums, 2);
    cout << res << endl;
    return 0;
}