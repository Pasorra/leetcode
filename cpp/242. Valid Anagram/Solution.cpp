#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int arr[26] = {0};
        for (char c : s)
        {
            arr[c - 97] += 1;
        }
        for (char c : t)
        {
            arr[c - 97] -= 1;
        }
        for (int i : arr)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->isAnagram("anagram", "nagaram");
    cout << res << endl;
    return 0;
}