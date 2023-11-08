#include <iostream>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int result = 0;
        int hasOdd = 0;
        int letters[52] = {0};
        for (char c : s)
        {
            int index;
            if (islower(c))
            {
                index = c - 'a';
            }
            else
            {
                index = c - 'A' + 26;
            }
            letters[index]++;
        }
        for (int num : letters)
        {
            if (num % 2 == 0)
            {
                result += num;
            }
            else if (num != 0)
            {
                hasOdd = 1;
                result += (num - 1);
            }
        }
        return result + hasOdd;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->longestPalindrome("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << res << endl;
    return 0;
}