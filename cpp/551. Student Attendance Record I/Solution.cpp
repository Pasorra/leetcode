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
    bool checkRecord(string s)
    {
        int absent = 0;
        int late = 0;
        for (char c : s)
        {
            if (c == 'A')
                absent++;

            if (c == 'L')
                late++;
            else
                late = 0;

            if (absent == 2 || late == 3)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->checkRecord("LLALA");
    cout << res << endl;
    return 0;
}