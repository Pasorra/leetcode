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
    bool repeatedSubstringPattern(string s)
    {
        int size = 1;
        while (size <= s.size() / 2)
        {
            int i = 0;
            int j = size;
            bool loopFailed = false;
            while (j < s.size())
            {
                if (s[i] != s[j])
                {
                    loopFailed = true;
                    break;
                }
                i = (i + 1) % size;
                j++;
            }
            if (!loopFailed)
            {
                return true;
            }
            size++;
            while (s.size() % size != 0)
            {
                size++;
            }
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->repeatedSubstringPattern("aabaaba");
    cout << res << endl;
    return 0;
}