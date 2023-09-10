#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            int val = (columnNumber - 1) % 26 + 1;
            result += static_cast<char>(val + 64);
            columnNumber = (columnNumber - val) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->convertToTitle(701);
    cout << res << endl;
}