#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
                if (i == 0)
                {
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
        }
        return digits;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> digits = {9, 9};
    s->plusOne(digits);
    for (int val : digits)
    {
        cout << val << ", ";
    }
    cout << endl;
}