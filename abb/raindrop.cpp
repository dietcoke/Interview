class Solution {
public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        // Write your code here
        if(V == 0)
        {
            return heights;
        }

        int n = heights.size();

        while(V--)
        {
            int t = K;
            for(int d=-1; d<=1; d+=2)
            {
                int i = t;
                while(i+d>=0 && i+d<n && heights[i+d]<=heights[i])
                {
                    if(heights[i+d]<heights[i])
                    {
                        t = i+d;
                    }

                    i+=d;
                }

                if(t!=K)
                {
                    break;
                }
            }

            heights[t]++;
        }

        return heights;
    }
};
