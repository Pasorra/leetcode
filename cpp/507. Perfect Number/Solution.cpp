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
    bool checkPerfectNumber(int num)
    {
        int tempNum = num - 1;
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                tempNum -= i;
                if (tempNum < 0)
                {
                    return false;
                }
            }
        }
        return (tempNum == 0) && num != 1;
    }
};

int main()
{
    Solution *s = new Solution();
    for (int i = 10; i < 1000; i++)
    {
        bool res = s->checkPerfectNumber(i);
        cout << res << ", " << i << endl;
    }
    return 0;
}