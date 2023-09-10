#include <iostream>
using namespace std;

class MyStack
{
public:
    // problem says "At most 100 calls will be made to push, pop, top, and empty."
    int stack[101];
    int index = 0;

    void push(int x)
    {
        stack[index] = x;
        index++;
    }

    int pop()
    {
        index--;
        int val = stack[index];
        return val;
    }

    int top()
    {
        return stack[index - 1];
    }

    bool empty()
    {
        return index == 0;
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_1 = obj->top();
    int param_2 = obj->pop();
    int param_3 = obj->empty();
    cout << param_1 << param_2 << param_3 << endl;
    return 0;
}