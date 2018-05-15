class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst)
        {
            return 0;
        }
        
        vector<vector<pair<int, int>>> g(n);
        for(auto & f : flights)
        {
            g[f[0]].push_back({f[1], f[2]});
        }
        
        auto comp = [](vector<int> & v1, vector<int> & v2)
        {
            return v1[0] > v2[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        vector<int> dist(n, INT_MAX/2);
        pq.push({0, src, K+1});
        
        while(pq.size()>0)
        {
            auto cur = pq.top();
            pq.pop();
            
            auto cost = cur[0];
            auto node = cur[1];
            auto leftChance = cur[2];
            
            if(node == dst)
            {
                return cost;
            }
            
            if(leftChance==0)
            {
                continue;
            }
            
            for(auto &next : g[node])
            {
                int y = next.first;
                int w = next.second;
                
                pq.push({cost + w, y, leftChance-1});
            }
        }
        
        return -1;
    }
};
