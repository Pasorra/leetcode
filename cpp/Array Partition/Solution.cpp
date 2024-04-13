#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    inline int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (size_t i = 0; i < nums.size(); i += 2)
        {
            res += nums[i];
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {1, 2, 3, 4};
    int res = s->arrayPairSum(v);
    cout << res << endl;
    return 0;
}