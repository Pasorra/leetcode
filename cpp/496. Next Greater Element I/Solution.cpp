#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            int found = findIndex(nums2, nums1[i]);
            res[i] = nextGreater(nums2, nums1[i], found + 1);
        }
        return res;
    }
    int findIndex(vector<int> &nums, int val)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (val == nums[i])
            {
                return i;
            }
        }
        return -1;
    }

private:
    int nextGreater(vector<int> &nums, int val, int searchStartIndex)
    {
        for (int i = searchStartIndex; i < nums.size(); i++)
        {
            if (nums[i] > val)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = s->nextGreaterElement(nums1, nums2);
    printVector(res);
    return 0;
}