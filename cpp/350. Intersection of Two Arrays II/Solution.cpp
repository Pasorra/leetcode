#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (map[nums2[i]] > 0)
            {
                result.push_back(nums2[i]);
                map[nums2[i]] -= 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4};
    vector<int> res = s->intersect(nums1, nums2);
    for (auto v : res)
    {
        cout << v << ", ";
    }
    return 0;
}