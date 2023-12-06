#include <iostream>
#include <vector>
#include <bitset>
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
    int findComplement(int num)
    {
        int res = 0;
        int accum = 1;
        while (num)
        {
            res += !(num & 1) * accum;
            accum <<= 1;
            num >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->findComplement(1);
    cout << res << endl;
    return 0;
}