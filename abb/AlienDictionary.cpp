// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

//  Notice
// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return the smallest in lexicographical order
// Have you met this question in a real interview? 
// Example
// Given the following words in dictionary,

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf"

// Given the following words in dictionary,

// [
//   "z",
//   "x"
// ]
// The correct order is: "zx".


class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        if(words.size()==0)
        {
            return "";
        }
        
        unordered_map<char, unordered_set<char>> g;
        for(auto & word : words)
        {
            for(auto ch : word)
            {
                g[ch] = unordered_set<char>();
            }
        }
        
        vector<int> ind(26, 0);
        
        int chars = g.size();
        
        int n = words.size();
        
        for(int i=0; i<n-1; i++)
        {
            int pos = diff(words[i], words[i+1]);
            if(pos>=0)
            {
                g[words[i][pos]].insert(words[i+1][pos]);
                ind[words[i+1][pos]-'a']++;
            }
        }
        
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0; i<26; i++)
        {
            if(g.find(i+'a') != g.end() && ind[i]==0)
            {
                pq.push(i);
            }
        }
        
        string result;
        while(pq.size()>0)
        {
            auto cur = pq.top();
            pq.pop();
            
            result.push_back(cur+'a');
            
            for(auto next : g[cur+'a'])
            {
                ind[next-'a']--;
                if(ind[next-'a'] ==0)
                {
                    pq.push(next-'a');
                }
            }
        }
        
        return result.size() == chars? result : "";
    }
    
    int diff(string & a, string & b)
    {
        int m = a.size();
        int n = b.size();
        
       
        for(int i=0; i<min(m,n); i++)
        {
            if(a[i]!=b[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};
