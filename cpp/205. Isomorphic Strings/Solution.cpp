#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_set<char> setS;
        unordered_set<char> setT;
        unordered_set<string> setCombo;
        string newStr = "  ";

        for (int i = 0; i < s.size(); i++)
        {
            setS.insert(s[i]);
            setT.insert(t[i]);
            newStr[0] = s[i];
            newStr[1] = t[i];
            setCombo.insert(newStr);
        }

        return setS.size() == setT.size() && setT.size() == setCombo.size();
    }
};

int main()
{
    Solution s;

    bool res = s.isIsomorphic("egg", "add");
    cout << res << endl;

    return 0;
}
