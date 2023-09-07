#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanNumerals = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int result = 0;
        char lastC = ' ';
        for (char c : s)
        {
            result += romanNumerals[c];
            switch (c)
            {
            case 'V':
            case 'X':
                if (lastC == 'I')
                {
                    result -= 2;
                }
                break;
            case 'L':
            case 'C':
                if (lastC == 'X')
                {
                    result -= 20;
                }
                break;
            case 'D':
            case 'M':
                if (lastC == 'C')
                {
                    result -= 200;
                }
                break;
            }
            lastC = c;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->romanToInt("MCMXCIV");
    cout << res << endl;
    return 0;
}