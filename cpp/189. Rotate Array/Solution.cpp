#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        int i = size - (k % size);
        if (size == 1 || i == 0 || i == size)
        {
            return;
        }

        vector<int> newNums;

        for (int x = 0; x < size; x++)
        {
            newNums.push_back(nums[i]);
            i = (i + 1) % size;
        }
        nums = newNums;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> a = {1, 2};
    s->rotate(a, 2);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}