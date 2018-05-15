class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        next.resize(26);
        isEnd = false;
        str = "";
    }
    
    vector<TrieNode *> next;
    bool isEnd;
    string str;
};

class Solution {
public:
    /**
     * @param board a list of lists of character
     * @param words a list of string
     * @return an integer
     */
    int boggleGame(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        int m = board.size();
        if (m == 0) {
            return 0;
        }
        int n = board[0].size();
        
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            insert(word, root);
        }
        
        maxCount = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, visited, root, 0);
            }
        }
        return maxCount;
    }
    
private:
    int maxCount;
    void insert(string word, TrieNode* root) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
        node->str = word;
    }
    
    void dfs(vector<vector<char> > &board, int x, int y, 
             vector<vector<bool>>& visited,
             TrieNode* root, int count) {
                 
        int m = board.size();
        int n = board[0].size();
        for (int i = x; i < m; ++i) {
            for (int j = y; j < n; ++j) {
                vector<vector<int>> visitedPaths;
                vector<int> paths;
                findNextWord(board, i, j, visited, root, root, paths, visitedPaths, count);
                for (auto path : visitedPaths) {
                    for (int pos : path) {
                        visited[pos / n][pos % n] = true;
                    }
                    
                    dfs(board, i, j, visited, root, count + 1);
                    
                    for (int pos : path)
                    {
                        visited[pos / n][pos % n] = false;
                    }
                }
    
            }
            y = 0;
        }
    }

    
    void findNextWord(vector<vector<char> > &board, int i, int j,
                      vector<vector<bool>>& visited,
                      TrieNode* root, TrieNode* currNode,
                      vector<int>& paths,
                      vector<vector<int>>& visitedPaths, int count) {
        char c = board[i][j];
        if (visited[i][j] || currNode->next[c - 'a'] == nullptr) {
            return;
        }
        
        currNode = currNode->next[c - 'a'];
        int m = board.size();
        int n = board[i].size();
        paths.push_back(i * n + j);
        if (currNode->isEnd) {
            visitedPaths.push_back(paths);
            maxCount = max(maxCount, count + 1);
        } else {
            visited[i][j] = true;
            if (i > 0) {
                findNextWord(board, i - 1, j, visited, root, currNode, paths, visitedPaths, count);
            }
            if (i < board.size() - 1) {
                findNextWord(board, i + 1, j, visited, root, currNode, paths, visitedPaths, count);
            }
            if (j > 0) {
                findNextWord(board, i, j - 1, visited, root, currNode, paths, visitedPaths, count);
            }
            if (j < board[i].size() - 1) {
                findNextWord(board, i, j + 1, visited, root, currNode, paths, visitedPaths, count);
            }
            visited[i][j] = false;
        }
        paths.pop_back();
    }
};
