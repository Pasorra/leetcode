#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            string s = "";
            if (i % 3 == 0)
            {
                s += "Fizz";
            }
            if (i % 5 == 0)
            {
                s += "Buzz";
            }
            else if (s.size() == 0)
            {
                s += to_string(i);
            }
            res.push_back(s);
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->fizzBuzz(10);
    cout << res << endl;
    return 0;
}