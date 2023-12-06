#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        int sizeBig = num1.size();
        int sizeSmall = num2.size();

        if (sizeSmall > sizeBig)
        {
            swap(num1, num2);
            swap(sizeBig, sizeSmall);
        }
        int padding = sizeBig - sizeSmall;

        for (int i = sizeSmall - 1; i >= 0; i--)
        {
            int a1 = (num1[i + padding] - '0');
            int a2 = (num2[i] - '0');
            int val = a1 + a2 + carry;
            if (val >= 10)
            {
                carry = 1;
                val -= 10;
            }
            else
            {
                carry = 0;
            }
            num1[i + padding] = static_cast<char>(val + '0');
        }
        padding--;
        while (carry && padding >= 0)
        {
            int val = (num1[padding] - '0') + carry;
            if (val >= 10)
            {
                carry = 1;
                val -= 10;
            }
            else
            {
                carry = 0;
            }
            num1[padding] = static_cast<char>(val + '0');
            padding--;
        }
        if (carry)
        {
            num1 = '1' + num1;
        }
        return num1;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->addStrings("1", "9");
    cout << res << endl;
    return 0;
}