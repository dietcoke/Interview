// For	example,	Given	2d	vector	=	 [ [1,2],	[3],	[4,5,6]	]	
// By	calling	next	repeatedly	until	hasNext	returns	false,	the	order	of	elements	returned	by	next	should	be:	
// [1,2,3,4,5,6].	
// • boolean	hasNext()	return	true	if	there	is	another	element	in	the	set
// • int	next()	return	the	value	of	the	next	element	in	the	array
// • void	remove()
// o remove	the	last	element	returned	by	the	iterator.
// o That	is,	remove	the	element	that	the	previous	next()	returned.
// o This	method	can	be	called	only	once	per	call	to	next(),	otherwise	an	exception	will	be	
// thrown.	
// Removes	from	the	underlying	collection	the	last	element	returned	by	this	iterator	(optional	operation).	
// This	method	can	be	called	only	once	per	call	to	next().	The	behavior	of	an	iterator	is	unspecified	if	the	
// underlying	collection	is	modified	while	the	iteration	is	in	progress	in	any	way	other	than	by	calling	this	
// method.
// So	the	remove()	method	actually	removes	the	element	returned	from	the	next().
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=167190
// remove 是 remove 上一个 getNext()	get 到的数。就是说不 remove	还没 getNext 的数的意思
// 举个例子：
// 如果函数被 call 的顺序是这样的：hasnext()	getnext()	hasnext()	getnext()	remove()
// 假设 data	是 ［［1，2］［3］］
// 那么返回 true,	1,	true,	2,	void	
// data 变为 [[1],	[3]]
typedef list<list<int>>::iterator RowIter;
typedef list<int>::iterator ColIter;

class TwoDIterator {
public:
	TwoDIterator(list<list<int>> data)
	{
		this->data = data;
		riter = this->data.begin();
		citer = riter->begin();
	}

	bool hasNext()
	{
		while ((citer == riter->end()) && riter != --data.end())
		{
			riter++;
			citer = riter->begin();
		}

		return citer != riter->end() && riter != data.end();
	}

	int next()
	{
		if (lastCIter.size() == 0)
		{
			lastCIter.push_back(citer);
			lastRIter.push_back(riter);
		}
		else
		{
			lastCIter[0] = citer;
			lastRIter[0] = riter;
		}

		int result = *citer;
		citer++;

		return result;
	}

	void remove()
	{
		if (lastCIter.size() == 0)
		{
			return;
		}

		(*lastRIter[0]).erase(lastCIter[0]);
	}

private:
	list<list<int>> data;
	RowIter riter;
	ColIter citer;
	vector<ColIter> lastCIter;
	vector<RowIter> lastRIter;
};
