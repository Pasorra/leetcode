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
    string reverseStr(string s, int k)
    {
        int index = 0;
        while (index + k - 1 < s.size())
        {
            reverse(s, index, k);
            index += 2 * k;
        }
        if (index < s.size())
        {
            reverse(s, index, s.size() - index);
        }
        return s;
    }

private:
    inline void reverse(string &s, int index, int k)
    {
        int end = index + k - 1;
        for (size_t i = 0; i < k / 2; i++)
        {
            swap(s[index + i], s[end - i]);
        }
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->reverseStr("abcdefg", 8);
    cout << res << endl;
    return 0;
}