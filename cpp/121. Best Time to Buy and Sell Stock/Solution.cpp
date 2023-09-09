#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lowest = INT32_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int price = prices[i];
            int val = price - lowest;
            result = val > result ? val : result;
            lowest = lowest > price ? price : lowest;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int res = s->maxProfit(prices);
    cout << res << endl;
}