#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    inline string reverseWords(string s)
    {
        int start = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverseWord(s, start, i - 1);
                start = i + 1;
            }
        }
        reverseWord(s, start, s.size() - 1);
        return s;
    }
    inline void reverseWord(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->reverseWords("asdasd sad sad");
    cout << res << endl;
    return 0;
}