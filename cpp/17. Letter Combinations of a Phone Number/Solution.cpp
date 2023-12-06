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
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {0, 0, 0, 0};
    vector<string> res = s->letterCombinations("2");
    printVector(res);

    return 0;
}