#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res = "";
        int carry = 0;
        int size1 = num1.size();
        int size2 = num2.size();

        if (size2 > size1)
        {
            swap(num1, num2);
            swap(size1, size2);
        }
        int padding = size1 - size2;

        for (int i = num2.size() - 1; i >= 0; i--)
        {
            int a1 = (num1[i + padding] - 48);
            int a2 = (num2[i] - 48);
            int val = a1 + a2 + carry;
            if (val >= 10)
            {
                carry = 1;
                val %= 10;
            }
            else
            {
                carry = 0;
            }
            res.insert(res.begin(), static_cast<char>(val + 48));
        }
        if (padding)
        {
            int index = padding - 1;
            while (index >= 0 && carry)
            {
                int val = num1[index] - 48 + carry;
                if (val >= 10)
                {
                    carry = 1;
                    val %= 10;
                }
                else
                {
                    carry = 0;
                }
                res.insert(res.begin(), static_cast<char>(val + 48));
                index--;
            }
            if (index >= 0)
            {
                res.insert(res.begin(), num1.begin(), num1.begin() + index + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->addStrings("1", "9");
    cout << res << endl;
    return 0;
}