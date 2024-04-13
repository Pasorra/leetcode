#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.size();
        if (size <= 1)
        {
            return size;
        }

        int result = 0;
        int left = 0;
        int charPos[256];
        fill_n(charPos, 256, -1);

        for (int right = 0; right < size; right++)
        {
            if (charPos[s[right]] != -1)
            {
                left = max(left, charPos[s[right]] + 1);
            }
            charPos[s[right]] = right;
            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->lengthOfLongestSubstring("pwwkew");
    cout << res << endl;
    return 0;
}