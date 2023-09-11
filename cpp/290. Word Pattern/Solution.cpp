#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        vector<string> words;
        unordered_map<char, string> map;
        unordered_set<string> set;
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        if (words.size() != pattern.size())
        {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++)
        {
            if (map[pattern[i]] == "")
            {
                if (set.find(words[i]) != set.end())
                {
                    return false;
                }
                map[pattern[i]] = words[i];
                set.insert(words[i]);
            }
            else
            {
                if (map[pattern[i]] != words[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool res = s->wordPattern("abba", "dog dog dog dog");
    cout << res << endl;
    return 0;
}