#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution
{

public://1������֮��
	//����һ��������ⷨ��Ҳ����ö�ٳ�ÿһ�ֿ���
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

	//����������ϣ��
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

public://2��������
	bool isPalindrome(int x)
	{
		//��Ҫ�ȴ������������
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		
		int revertedNumber = 0;
		while (x > revertedNumber)
		{
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		//��������λ��ż��λ
		return x == revertedNumber || x == revertedNumber / 10;
	}
	//=======================================================================

public://3����������ת����
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
				ans -= value; //��һ�������Ҳ���������������ȡ��
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
		cout << "���Ϊ" << target << "��Ԫ������Ϊ:" << result[0] << "," << result[1] << endl;
	else
		cout << "Not Find!" << endl;
}

void reverted_Number()
{
	int num = 1291;

	Solution s;
	
	if (s.isPalindrome(num))
		cout << num << "�ǻ�������" << endl;
	else
		cout << num << "���ǻ�������" << endl;

}

void romanToInt()
{
	string s = "LVX";
	Solution sp;
	cout << s << " �Ķ�Ӧ����Ϊ��" << sp.romanToInt(s) << endl;
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