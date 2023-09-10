#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int size = s.size();
        int left = 0;
        int right = size - 1;

        while (left < right)
        {
            char leftChar = tolower(s[left]);
            char rightChar = tolower(s[right]);

            while (left < right && !isAlphanumeric(leftChar))
            {
                left++;
                leftChar = tolower(s[left]);
            }
            while (left < right && !isAlphanumeric(rightChar))
            {
                right--;
                rightChar = tolower(s[right]);
            }
            if (leftChar != rightChar)
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isAlphanumeric(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->isPalindrome("A man, a plan, a canal: Panama");
    cout << res << endl;
}