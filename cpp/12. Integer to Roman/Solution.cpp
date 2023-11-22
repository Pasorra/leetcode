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
    string intToRoman(int num)
    {
        string res = "";
        int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string romans[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        while (i >= 0)
        {
            while (num >= nums[i])
            {
                res += romans[i];
                num -= nums[i];
            }
            i--;
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->intToRoman(1994);
    cout << res << endl;
    return 0;
}