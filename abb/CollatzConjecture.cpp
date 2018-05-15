// https://en.wikipedia.org/wiki/Collatz_conjecture
// 题目是给你公式，比如偶数的话除 2，奇数的话就变成 3*n+1，对于任何一个正数，数学猜想是最
// 终他会变成 1。每变一步步数加 1，给一个上限，让找出范围内最长步数。

class Solution {
public:
	int findLongestSteps(int num)
	{
		if (num < 1)
		{
			return 0;
		}

		if (num == 1)
		{
			return 1;
		}

		//[1,num]
		unordered_map<long long, int> memo;

		int result = 1;
		for (int i = 2; i <= num; i++)
		{
			int t = findStep(i, memo);
			result = max(result, t);
		}

		return result;
	}

	int findStep(long long num, unordered_map<long long, int> & memo)
	{
		if (num <= 1)
		{
			return 1;
		}

		if (memo.find(num) != memo.end())
		{
			return memo[num];
		}

		int t = 0;
		if (num % 2 == 0)
		{
			t = findStep(num / 2, memo) + 1;
		}
		else
		{
			t= findStep(3 * num + 1, memo) + 1;
		}

		memo[num] = t;

		return t;
	}
};

int main()
{
	vector<vector<int>> tests = {
		{ 1,1 },
	{ 10, 20 },
	{ 37, 112 },
	{ 7, 17 },
	{ 101, 119 }
	};

	Solution s;
	for (auto & t : tests)
	{
		auto cur = s.findLongestSteps(t[0]);
		if (t[1] == cur)
		{
			cout << "p" << endl;
		}
		else
		{
			cout << "f" << endl;
		}
	}

	cin.get();
}
