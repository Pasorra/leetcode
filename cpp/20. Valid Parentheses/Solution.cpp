#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> charStack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                charStack.push(c);
            }
            else if (c == ')' && !charStack.empty() && charStack.top() == '(')
            {
                charStack.pop();
            }
            else if (c == '}' && !charStack.empty() && charStack.top() == '{')
            {
                charStack.pop();
            }
            else if (c == ']' && !charStack.empty() && charStack.top() == '[')
            {
                charStack.pop();
            }
            else
            {
                return false;
            }
        }
        return charStack.empty();
    }
};

int main()
{
    Solution *s = new Solution();
    int res = s->isValid("]");
    cout << res << endl;
    return 0;
}