#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << endl;
}

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> ranks(score.size(), 1);
        for (size_t i = 0; i < score.size(); i++)
        {
            for (size_t x = i + 1; x < score.size(); x++)
            {
                if (score[i] < score[x])
                {
                    ranks[i]++;
                }
                else
                {
                    ranks[x]++;
                }
            }
        }
        vector<string> res(score.size());
        for (size_t i = 0; i < score.size(); i++)
        {
            switch (ranks[i])
            {
            case 1:
                res[i] = "Gold Medal";
                break;
            case 2:
                res[i] = "Silver Medal";
                break;
            case 3:
                res[i] = "Bronze Medal";
                break;
            default:
                res[i] = to_string(ranks[i]);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> res = s->findRelativeRanks(score);
    printVector(res);
    return 0;
}