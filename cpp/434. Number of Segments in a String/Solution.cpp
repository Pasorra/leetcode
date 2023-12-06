#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        bool prevWasChar = false;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (prevWasChar && s[i] == ' ' && (i == s.size() - 1 || s[i + 1] != ' '))
            {
                prevWasChar = false;
                res++;
            }
            else if (s[i] != ' ')
            {
                prevWasChar = true;
            }
        }

        return res + prevWasChar;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->countSegments("0 a");
    cout << res << endl;
    return 0;
}