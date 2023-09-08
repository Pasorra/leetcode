#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// '0' = 48

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int sizeA = a.size();
        int sizeB = b.size();
        if (sizeB > sizeA)
        {
            swap(a, b);
            swap(sizeA, sizeB);
        }
        int padding = sizeA - sizeB;
        int carry = 0;
        ostringstream result;
        for (int i = sizeA - 1; i >= 0; i--)
        {
            int val;
            if (i - padding < 0)
            {
                val = a[i] + carry - 48;
            }
            else
            {
                val = a[i] + b[i - padding] + carry - 96;
            }

            if (val == 3)
            {
                carry = 1;
                // result.insert(result.begin(), '1');
                result << '1';
            }
            else if (val == 2)
            {
                carry = 1;
                // result.insert(result.begin(), '0');
                result << '0';
            }
            else if (val == 1)
            {
                carry = 0;
                // result.insert(result.begin(), '1');
                result << '1';
            }
            else if (val == 0)
            {
                carry = 0;
                // result.insert(result.begin(), '0');
                result << '0';
            }
        }
        if (carry == 1)
        {
            // result.insert(result.begin(), '1');
            result << '1';
        }
        string finalResult = result.str();
        reverse(finalResult.begin(), finalResult.end());
        return finalResult;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->addBinary("11", "1");
    cout << res << endl;
}