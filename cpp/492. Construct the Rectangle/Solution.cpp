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
    vector<int> constructRectangle(int area)
    {
        vector<int> res = findDivisors(area);
        if (res.size() % 2 == 0)
        {
            return vector<int>{res[res.size() / 2], res[(res.size() / 2) - 1]};
        }
        return vector<int>{res[res.size() / 2], res[res.size() / 2]};
    }
    vector<int> findDivisors(int num)
    {
        vector<int> res = {1};
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                res.push_back(i);
            }
        }
        res.push_back(num);
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> res = s->constructRectangle(122122);
    printVector(res);
    return 0;
}