#include <iostream>
#include <vector>
#include <algorithm>
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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (int child : g)
        {
            for (size_t i = 0; i < s.size(); i++)
            {
                if (child <= s[i])
                {
                    res++;
                    s[i] = 0;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> g = {3, 2, 1, 4, 5};
    vector<int> sizes = {1, 2, 3, 10};
    int res = s->findContentChildren(g, sizes);
    cout << res << endl;
    return 0;
}