#include <string>
#include <vector>
#include <iostream>


class Solution{
public:
	int LS(std::string s)
	{
		//定义一个长度为256的数组，及其他辅助变量
		std::vector<int> v(256,-1);
		int last = 0, len = s.size(), maxlen = 0;

		//
		for(int i = 0; i < len; ++i)
		{
			if(-1 != v[s[i]])
			{
				maxlen = std::max(maxlen, i - last);
				for(int j = last; j < v[s[i]]; ++j)
				{
					v[s[j]] = -1;
				}
				last = v[s[i]] + 1; //重新设置位置
				v[s[i]] = i;
			}
			else
			{
				v[s[i]] = i;
			}
		}
		return std::max(maxlen, len - last);
	}
};

int main(int argc, char const *argv[])
{
	std::string s(512,0);
	Solution sol;

	while(std::cin >> s)
	{
		std::cout << sol.LS(s) << std::endl;
	}
	return 0;
}