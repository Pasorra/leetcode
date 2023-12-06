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
    int arrangeCoins(int n)
    {
        // we need the lowest res where (res * (res+1))/2 <= n
        unsigned long long res = 1;
        while (res * (res + 1) / 2 <= n)
        {
            res++;
        }
        return res - 1;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->arrangeCoins(1804289383);
    cout << res << endl;
    return 0;
}