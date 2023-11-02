#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "")
        {
            return true;
        }
        int ind = 0;
        for (char c : t)
        {
            if (c == s[ind])
            {
                ind++;
                if (ind == s.size())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isSubsequence("as", " aejfoweıjas");
    cout << res << endl;
    return 0;
}