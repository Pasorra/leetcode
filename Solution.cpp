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
    int boilerplate()
    {
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->boilerplate();
    cout << res << endl;
    return 0;
}