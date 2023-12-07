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
    vector<string> findWords(vector<string> &words)
    {
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> res;
        for (string word : words)
        {
            bool foundInRow = false;
            bool cant = false;
            for (int i = 0; i < 3; i++)
            {
                for (char ch : word)
                {
                    if (!findChar(rows[i], tolower(ch)))
                    {
                        if (foundInRow)
                        {
                            cant = true;
                        }
                        break;
                    }
                    foundInRow = true;
                }
                if (cant)
                {
                    break;
                }
                else if (foundInRow)
                {
                    break;
                }
            }
            if (!cant)
            {
                res.push_back(word);
            }
        }
        return res;
    }

private:
    bool findChar(const string &str, const char &ch)
    {
        for (char character : str)
        {
            if (character == ch)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> res = s->findWords(words);
    printVector(res);
    return 0;
}