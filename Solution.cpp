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
    cout << v[v.size() - 1];
}

class Solution
{
public:
    bool boilerplate()
    {
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->boilerplate();
    cout << res << endl;
    return 0;
}