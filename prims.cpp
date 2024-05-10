class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        vector<int> vis(V,0);
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});
        //vis[0] = 1;
        while(!pq.empty())
        {
            pair<int,int> temp = pq.top();
            int wt = temp.first;
            int node = temp.second;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            ans += wt;
            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int edw = it[1];
                if(!vis[adjNode])
                {
                    pq.push({edw , adjNode});
                }
            }
            
        }
        
        return ans;
    }
};