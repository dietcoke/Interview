class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.size()<1)
        {
            return false;
        }

        if(bottom.size()==1)
        {
            return true;
        }

        vector<vector<char>> allows(49, vector<char>());
        for(auto a : allowed)
        {
            allows[(a[0]-'A') * 7 + a[1]-'A'].push_back(a[2]);
        }

        unordered_set<string> invalid;
        
        return find(bottom, allows, invalid);
    }

    bool find(string & bottom, vector<vector<char>> & allows, unordered_set<string> & invalid)
    {
        if(bottom.size()==1)
        {
            return true;
        }

        if(invalid.find(bottom) != invalid.end())
        {
            return false;
        }

        string next;
        if(tryFind(bottom, 0, next, allows, invalid))
        {
            return true;
        }

        invalid.insert(bottom);

        return false;
    }

    bool tryFind(string & bottom, int index, string & next, vector<vector<char>> & allows, unordered_set<string> & invalid)
    {
        if(index == bottom.size()-1)
        {
            return find(next, allows, invalid);
        }

        int key = (bottom[index] -'A') * 7 + bottom[index+1] -'A';
        for(auto a : allows[key])
        {
            next.push_back(a);
            if(tryFind(bottom, index+1, next, allows, invalid))
            {
                return true;
            }
            next.pop_back();
        }

        invalid.insert(bottom);

        return false;
    }


};
