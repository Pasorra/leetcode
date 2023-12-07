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
    string licenseKeyFormatting(string s, int k)
    {
        string res = "";
        int size = 0;
        for (auto c : s)
        {
            if (c != '-')
            {
                size++;
            }
        }
        int chunk = (size % k == 0) ? k : (size % k);
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                continue;
            }
            if (chunk == 0)
            {
                res += '-';
                chunk = k;
            }
            res += toupper(s[i]);
            chunk--;
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->licenseKeyFormatting("2-5g-3-J", 2);
    cout << res << endl;
    return 0;
}