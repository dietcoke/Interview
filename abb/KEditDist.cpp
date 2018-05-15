class TrieNode
{
public:
    string w;
    bool hasWord;
    vector<TrieNode *> next;
    
    TrieNode()
    {
        w = "";
        hasWord = false;
        next = vector<TrieNode *>(26, NULL);
    }
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        buildTree(words);
        
        int n = target.size();
        
        vector<int> dp(n+1, 0);
        for(int i=0; i<=n; i++)
        {
            dp[i] = i;
        }
        
        vector<string> result;
        find(root, target, k, dp, result);
        
        return result;
    }
    
    void find(TrieNode * cur, string & target, int k, vector<int> & dp, vector<string> & result)
    {
        int n = target.size();
        
        if((cur->hasWord) && dp[n]<=k)
        {
            result.push_back(cur->w);   
        }
        
        vector<int> dpNext(n+1, 0);
        for(int i=0; i<=n; i++)
        {
            dpNext[i] = dp[i]+1;
        }
        
        for(int i=0; i<26; i++)
        {
            if(!cur->next[i])
            {
                continue;
            }
            
            for(int j=0; j<n; j++)
            {
                if(target[j] == (i + 'a'))
                {
                    dpNext[j+1] = min(dp[j], min(dpNext[j]+1, dp[j+1]+1));
                }
                else
                {
                    dpNext[j+1] = min(dp[j]+1, min(dpNext[j]+1, dp[j+1]+1));
                }
            }
            
            find(cur->next[i], target, k, dpNext, result);
        }
    }
    
    void buildTree(vector<string> &words)
    {
        root = new TrieNode(); 
        for(auto & w : words)
        {
            addNode(w);
        }
    }
    
    void addNode(string & w)
    {
        auto cur = root;
        for(auto ch : w)
        {
            int index = ch - 'a';
            if(!cur->next[index])
            {
                cur->next[index] = new TrieNode(); 
            }
            
            cur = cur->next[index];
        }
        
        cur->w = w;
         cur->hasWord = true;
    }
    
    TrieNode * root;
};
