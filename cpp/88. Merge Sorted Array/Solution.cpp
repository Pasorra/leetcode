#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            nums1.swap(nums2);
            return;
        }
        if (n == 0)
        {
            return;
        }

        int mIndex = m - 1;
        int nIndex = n - 1;
        int lastIndex = nums1.size() - 1;
        while (lastIndex >= 0)
        {
            if (mIndex == -1)
            {
                swap(nums2[nIndex], nums1[lastIndex]);
                lastIndex--;
                nIndex--;
            }
            else if (nIndex == -1)
            {
                swap(nums1[mIndex], nums1[lastIndex]);
                lastIndex--;
                mIndex--;
            }
            else if (nums1[mIndex] > nums2[nIndex])
            {
                swap(nums1[mIndex], nums1[lastIndex]);
                lastIndex--;
                mIndex--;
            }
            else
            {
                swap(nums2[nIndex], nums1[lastIndex]);
                lastIndex--;
                nIndex--;
            }
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums1 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    int m = 6;
    vector<int> nums2 = {1, 2, 2};
    int n = 3;
    s->merge(nums1, m, nums2, n);
    for (int val : nums1)
    {
        cout << val << ", ";
    }
    cout << endl;
}