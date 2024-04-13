#include <iostream>
#include <vector>
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
    inline vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if (r * c != mat.size() * mat[0].size())
            return mat;

        vector<vector<int>> res(r, vector<int>(c));
        int y = 0, x = 0;

        for (vector<int> v : mat)
        {
            for (int val : v)
            {
                res[y][x] = val;
                x++;
                if (x == c)
                {
                    x = 0;
                    y++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> v = {{1, 2}, {3, 4}};
    vector<vector<int>> res = s->matrixReshape(v, 1, 4);
    for (auto newV : res)
    {
        printVector(newV);
    }
    return 0;
}