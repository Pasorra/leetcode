#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> map;
        for (auto c : magazine)
        {
            map[c] += 1;
        }
        for (auto c : ransomNote)
        {
            if (map[c] <= 0)
            {
                return false;
            }
            map[c] -= 1;
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->canConstruct("abb", "ab");
    cout << res << endl;
    return 0;
}