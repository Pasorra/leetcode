#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// a ab aba b ba

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        int result = 0;
        int size = s.size();
        for (int start = 0; start < size; start++)
        {
            int arr[26] = {0};
            int count = 0;
            int onesCount = 0;
            for (int i = start; i < size; i++)
            {
                int *ptr = &arr[s[i] - 65];
                if (*ptr == 0)
                {
                    onesCount += 1;
                    *ptr = 1;
                }
                else if (*ptr == 1)
                {
                    onesCount -= 1;
                    *ptr = 2;
                }
                count += onesCount;
            }
            result += count;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int x = s.uniqueLetterString("ABA");
    cout << x << endl;
    return 0;
}