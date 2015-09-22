#include <iostream>
#include <string>

/*
    map：存储-1或字母在字符串中的位置
*/
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int map[256] = {0};
        int n = s.length();
        int res = 0;
        
        for (int i = 0; i < 256; ++i)
        {
            map[i] = -1;
        }
        
        int last = 0;
        int len = 0;
        /*
            每一次循环，字母的ASCII值作为下标通过map判断是否有重复的元素；遇到重复的元素，则将字符串[last,i]字符在map中的映射位置置为-1，当前的最长非重复元素子串为res和i-last的最大值（res记录上次最长的非重复元素子串长度,last记录的是重复元素中第一个元素的下一个位置）
        */
        for (int i = 0; i < n; ++i)
        {
            if (map[s[i]] == -1)
            {
                map[s[i]] = i;
                continue;
            }
            res = std::max(res, i - last);
            while (last <= map[s[i]])
            {
                map[s[last++]] = -1;
            }
            i--;
        }
        res = std::max(res, n - last);
        
        return res;
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
