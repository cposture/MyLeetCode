#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = 0, len = s.length();
        for (int i = 0; i != len; i++) {
            if (dict[s[i]] >= start)
            {
                maxLen = max(maxLen, i - start);
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
        }
        return max(maxLen, len - start);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;

    while (std::cin >> s)
    {
        std::cout << sln.lengthOfLongestSubstring(s) << std::endl;
    }

    return 0;
}