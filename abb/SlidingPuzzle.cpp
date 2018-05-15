class Solution {
public:
    /**
     * @param matrix: The 3*3 matrix
     * @return: The answer
     */

    int dirs[9][4] = {
        {1,3,-1,-1},
        {0,2,4,-1},
        {1,5,-1,-1},
        {0,4,6,-1},
        {1,3,5,7},
        {2,4,8,-1},
        {3,7,-1,-1},
        {4,6,8,-1},
        {5,7,-1,-1}
    };

    string  jigsawPuzzle(vector<vector<int>> &matrix) {
        string state(9, '0');
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                state[i*3+j] = matrix[i][j] + '0';
            }
        }

        if(state == "123456780")
        {
            return "YES";
        }

        unordered_map<string, bool> memo;
        unordered_set<string> visit;
        
        visit.insert(state);

        return find(state, memo, visit) ? "YES" : "NO";
    }

    bool find(string & state,  unordered_map<string, bool> & memo, unordered_set<string> & visit)
    {
        if(memo.find(state)!=memo.end())
        {
            return memo[state];
        }

        if(state == "123456780")
        {
            return true;
        }

        int z = 0;
        for(; z<9; z++)
        {
            if(state[z] == '0')
            {
                break;
            }
        }

        for(int d=0; d<4; d++)
        {
            if(dirs[z][d] == -1)
            {
                break;
            }

            swap(state[z], state[dirs[z][d]]);
            if(visit.find(state) == visit.end())
            {
                visit.insert(state);
                if(find(state, memo, visit))
                {
                    memo[state] = true;
                    return true;
                }
            }
            swap(state[z], state[dirs[z][d]]);
        }

        memo[state] = false;

        return false;
    }
};
