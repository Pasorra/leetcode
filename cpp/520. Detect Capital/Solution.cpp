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
    bool detectCapitalUse(string word)
    {
        int upperCount = 0;
        int lowerCount = 0;
        for (char c : word)
        {
            if (isupper(c))
            {
                upperCount++;
            }
            else
            {
                lowerCount++;
            }
            if (lowerCount > 1 && upperCount > 1)
            {
                return false;
            }
        }
        return (lowerCount == 0 && upperCount > 0) || (lowerCount > 0 && upperCount == 0) || (upperCount == 1 && isupper(word[0]));
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->detectCapitalUse("USA");
    cout << res << endl;
    return 0;
}