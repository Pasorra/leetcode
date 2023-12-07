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
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int temp = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                res = max(res, temp);
                temp = 0;
                continue;
            }
            temp++;
        }
        return max(res, temp);
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 0, 1, 1, 1};
    int res = s->findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}