#include <iostream>
#include <cstdlib>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int i = 1;
        chance = n;
        while (true)
        {
            if (isBadVersion(i))
            {
                return i;
            }
            i++;
        }
    }

private:
    int chance = 0;
    bool isBadVersion(int version)
    {
        double random = (double)rand() / RAND_MAX;
        double probability = (double)version / chance;
        return random <= probability;
    }
};
int main()
{
    Solution *s = new Solution();
    int res = s->firstBadVersion(14603600);
    cout << res << endl;
    return 0;
}