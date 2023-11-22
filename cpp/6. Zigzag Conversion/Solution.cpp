#include <iostream>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int distance = (2 * numRows) - 2;
        if (distance == 0)
        {
            return s;
        }
        string result = "";
        int strSize = s.size();
        int iterCount = 0;
        int left = distance;
        int right = 0;
        while (iterCount < numRows)
        {
            int index = iterCount;
            bool isLeft = true;
            while (index < strSize)
            {
                if (isLeft && left != 0)
                {
                    result += s[index];
                    index += left;
                }
                else if (!isLeft && right != 0)
                {
                    result += s[index];
                    index += right;
                }
                isLeft = !isLeft;
            }
            iterCount++;
            left -= 2;
            right += 2;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    string res = s->convert("A", 1);
    cout << res << endl;
    return 0;
}