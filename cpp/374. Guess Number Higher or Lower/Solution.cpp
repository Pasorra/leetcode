#include <iostream>
using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int min = 1;
        int max = n;
        while (min < max)
        {
            int middle = min + (max - min) / 2;
            int guessResult = guess(middle);
            if (guessResult == 0)
            {
                return middle;
            }
            else if (guessResult == -1)
            {
                min = middle + 1;
            }
            else
            {
                max = middle;
            }
        }
        return min;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->guessNumber(10);
    cout << res << endl;
    return 0;
}