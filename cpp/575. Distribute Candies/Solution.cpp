#include <iostream>
#include <vector>
#include <unordered_set>
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
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> s;
        for (size_t i = 0; i < candyType.size(); i++)
        {
            s.insert(candyType[i]);
        }
        return s.size() < candyType.size() / 2 ? s.size() : candyType.size() / 2;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {1, 2, 3, 4};
    int res = s->distributeCandies(v);
    cout << res << endl;
    return 0;
}