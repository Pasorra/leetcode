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
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int result = 0;
        while (z)
        {
            if (z & 1)
            {
                result++;
            }
            z >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->hammingDistance(1, 7);
    cout << res << endl;
    return 0;
}