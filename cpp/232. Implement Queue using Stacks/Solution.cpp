#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    MyQueue *s = new MyQueue();
    s->push(1);
    s->push(2);

    cout << s->pop() << endl;
    cout << s->peek() << endl;
    return 0;
}