//Design	a	Queue	with	arrayList,	但是有限制条件,	arraylist 的长度最多为 10,	queue 不限制长度。
typedef list<vector<int>>::iterator LITER;

class QueueWithFixedArray
{
public:
	QueueWithFixedArray(int fixSize)
	{
		if (fixSize<1)
		{
			//;
		}

		this->fixSize = fixSize;
		init();
	}

	void init()
	{
		q.push_back(vector<int>(fixSize));
		sLITER = q.begin();
		eLITER = q.begin();

		start = 0;
		end = 0;
		count = 0;
	}

	void enqueue(int num)
	{
		//process full

		if (end == fixSize - 1)
		{
			q.push_back(vector<int>(fixSize));
			eLITER = --q.end();
			end = 0;
		}

		(*eLITER)[end++] = num;
		count++;
	}

	int deque(int num)
	{
		if (count == 0)
		{
			//throw
			return 1;
		}

		int result = (*sLITER)[start++];
		count--;
		if (start == fixSize)
		{
			q.pop_front();
			if (q.size() == 0)
			{
				init();
			}
			else
			{
				start = 0;
				sLITER = q.begin();
			}
		}

		return result;
	}

private:
	int fixSize;
	int count;

	list<vector<int>> q;

	LITER sLITER;
	LITER eLITER;

	int start;
	int end;
};
