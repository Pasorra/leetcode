#include <iostream>
#include <vector>
using namespace std;

// Works on my machine but not on leetcode?

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int arr[3] = {INT32_MIN, INT32_MIN, INT32_MIN};
        for (int num : nums)
        {
            int value = num;
            for (int i = 0; i < 3; i++)
            {
                if (value > arr[i])
                {
                    int temp = arr[i];
                    arr[i] = value;
                    value = temp;
                }
                else
                {
                    break;
                }
            }
        }
        int ind = 2;
        while (ind > 0 && arr[ind] != INT32_MIN)
        {
            ind--;
        }
        return arr[ind];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> i = {3, 2, 1};
    bool res = s->thirdMax(i);
    cout << res << endl;
    return 0;
}