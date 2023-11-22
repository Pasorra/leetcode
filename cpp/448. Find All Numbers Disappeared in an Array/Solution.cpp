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
    cout << v[v.size() - 1];
}

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] - 1 != i && nums[nums[i] - 1] != nums[i])
            {
                cout << "Swapping " << nums[i] << " and " << nums[nums[i] - 1] << endl;
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - 1 != i)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> a = {1, 1};
    a = s->findDisappearedNumbers(a);
    printVector(a);
    return 0;
}