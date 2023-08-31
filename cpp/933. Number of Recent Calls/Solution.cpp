#include <queue>
#include <iostream>
using namespace std;

class RecentCounter
{
public:
    int ping(int t)
    {
        requests.push(t);
        int smallest = t - 3000;
        while (requests.front() < smallest)
        {
            requests.pop();
        }

        return requests.size();
    }

private:
    queue<int> requests;
};

int main()
{
    RecentCounter *s = new RecentCounter();
    s->ping(234);
    s->ping(235);
    int result = s->ping(236);
    cout << "Result: " << result << endl;
    return 0;
}