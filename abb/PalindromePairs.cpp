class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if(words.size()<2)
        {
            return {};
        }

        int n = words.size();

        unordered_map<string, int> index;
        for(int i=0; i<n; i++)
        {
            index[words[i]] = i;
        }

        vector<vector<int>> result;
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<=words[i].size(); j++)
            {
                auto left = words[i].substr(0, j);
                auto right = words[i].substr(j);

                if(left!= "" && isPalindrome(left))
                {
                    auto revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    if(index.find(revRight)!=index.end() && index[revRight] != i)  // && index[revRight] != i
                    {
                        result.push_back({index[revRight], i});
                    }
                }

                if(isPalindrome(right)) //right != "" &&
                {
                    auto revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    if(index.find(revLeft)!=index.end()  && index[revLeft] != i ) // && index[revLeft] != i
                    {
                        result.push_back({i, index[revLeft]});
                    }
                }
            }
        }

        return result;
    }

    bool isPalindrome(string & str)
    {
        int i = 0;
        int j = str.size()-1;
        while(i<j)
        {
            if(str[i++]!=str[j--])
            {
                return false;
            }
        }

        return true;
    }
};
