class Solution
{
public:
	vector<string> ip2CIDR(string ip, int range)
	{
		if (range == 0)
		{
			return {};
		}

		vector<string> result;
		auto ipl = ip2long(ip);
		auto r2int = rangeToint();

		while (range>0)
		{
			long long lastOne = ipl == 0 ? pow((long long)2, 32) : ipl & (-ipl);

			while (lastOne>range)
			{
				lastOne = lastOne >> 1;
			}

			result.push_back(tostring(ipl, r2int[lastOne]));

			range -= lastOne;
			ipl += lastOne;
		}

		return result;
	}

	string tostring(long long ip, int range)
	{
		string result = "";
		for (int i = 0; i<4; i++)
		{
			result = to_string((ip & 255)) + "." + result;
			ip = ip >> 8;
		}

		result = result + "/" + to_string(range);

		return result;
	}

	long long ip2long(string & ip)
	{
		long long result = 0;
		int n = ip.size();
		int i = 0;
		for (int j = 0; j <= n; j++)
		{
			if (j == n || ip[j] == '.')
			{
				result = result << 8;
				auto cur = stoi(ip.substr(i, j - i));
				result += cur;
				i = j + 1;
			}
		}

		return result;
	}

	map<int, int> rangeToint()
	{
		map<int, int> map;
		for (int i = 32; i >= 1; i--)
		{
			map[(int)pow(2, 32 - i)] = i;
		}

		return map;
	}
};
