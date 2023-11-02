#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int arr[26] = {0};
        for (char c : s)
        {
            arr[c - 'a'] += 1;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->firstUniqChar("hi");
    cout << res << endl;
    return 0;
}