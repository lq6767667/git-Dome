#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution
{

public://1、两数之和
	//方法一：暴力求解法，也就是枚举出每一种可能
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return { i,j };
				}
			}
		}
		return {};
	}

	//方法二：哈希表法
	vector<int> twoSum2(vector<int>& nums, int target)
	{
		unordered_map<int, int> hashMap;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = hashMap.find(target - nums[i]);
			if (it != hashMap.end())
			{
				return { it->second, i };
			}
			hashMap[nums[i]] = i;
		}
		return {};
	}
	//=======================================================================

public://2、回文数
	bool isPalindrome(int x)
	{
		//需要先处理特殊情况：
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		
		int revertedNumber = 0;
		while (x > revertedNumber)
		{
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		//处理奇数位和偶数位
		return x == revertedNumber || x == revertedNumber / 10;
	}
	//=======================================================================

public://3、罗马数字转整数
	int romanToInt(string str)
	{
		unordered_map<char, int> hashRom = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		int n = str.length();

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			int value = hashRom[str[i]];
			if (i < n-1 && value < hashRom[str[i + 1]])
				ans -= value; //若一个数字右侧的数比他大，则该数取反
			else
				ans += value;
		}
		return ans;
	}
};

void two_sum()
{
	vector<int> nums = { 2,11,15,7 };
	int target = 9;

	Solution s;
	vector<int> result = s.twoSum2(nums, target);
	if (!result.empty())
		cout << "结果为" << target << "的元素索引为:" << result[0] << "," << result[1] << endl;
	else
		cout << "Not Find!" << endl;
}

void reverted_Number()
{
	int num = 1291;

	Solution s;
	
	if (s.isPalindrome(num))
		cout << num << "是回文数！" << endl;
	else
		cout << num << "不是回文数！" << endl;

}

void romanToInt()
{
	string s = "LVX";
	Solution sp;
	cout << s << " 的对应整数为：" << sp.romanToInt(s) << endl;
}
int main()
{
	//two_sum();
	//reverted_Number();
	romanToInt();
	cout << endl;
	system("pause");
	return 0;
}