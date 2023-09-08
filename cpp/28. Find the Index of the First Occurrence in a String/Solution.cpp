#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int needleIndex = 0;
        int firstOccurrence = -1;
        int needleSize = needle.size();
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[needleIndex])
            {
                if (needleIndex == 0)
                {
                    firstOccurrence = i;
                }
                needleIndex++;
                if (needleIndex == needleSize)
                {
                    return firstOccurrence;
                }
            }
            else
            {
                needleIndex = 0;
                if (firstOccurrence != -1)
                {
                    i = firstOccurrence;
                }
                firstOccurrence = -1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->strStr("mississippi", "issip");
    cout << res << endl;
}