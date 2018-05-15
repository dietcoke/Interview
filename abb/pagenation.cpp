list<string> displayPage(list<string> & items, int pageSize)
{
	if (pageSize == 0)
	{
		return {};
	}

	if (pageSize == 1)
	{
		return items;
	}

	unordered_set<string> visit;
	bool reachEnd = false;
	list<string> result;
	auto iter = items.begin();
	int count = 0;
	while (items.size()>0)
	{
		auto old = iter++;
		if (visit.find(*old) == visit.end() || reachEnd)
		{
			result.push_back(*old);
			visit.insert(*old);
			items.erase(old);
			count++;
		}

		if (count == pageSize)
		{
			visit = unordered_set<string>();
			count = 0;
			reachEnd = false;
			iter = items.begin();
		}

		if (iter == items.end())
		{
			reachEnd = true;
			iter = items.begin();
		}

	}

	return result;
}
