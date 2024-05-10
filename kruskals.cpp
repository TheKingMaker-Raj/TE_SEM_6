// #include<bits/stdc++.h>
// using namespace std;

// class DisjointSet{
//     public:
//     vector<int> parent;
//     vector<int> rank;

//     DisjointSet(int n)
//     {
//         rank.resize(n,0);
//         parent.resize(n);
//         for(int i = 0 ; i<n ; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     int find_ultimate_parent(int node)
//     {
//         if(parent[node] == node) return node;
//         else
//         {
//             return parent[node] = find_ultimate_parent(parent[node]);
//         }
//     }

//     void union_by_rank(int u , int v)
//     {
//         int pu = find_ultimate_parent(u);
//         int pv = find_ultimate_parent(v);
//         if(pu>pv)
//         {
//             parent[v] = u;
//         }

//         else if(pv>pu)
//         {
//             parent[u] = v;
//         }

//         else
//         {
//             parent[u] = v;
//             rank[v]++;
//         }
//     }
// };

// int main()
// {
//     DisjointSet ds(7);
//     ds.union_by_rank(1,2);
//     ds.union_by_rank(2,3);
//     ds.union_by_rank(3,2);
//     ds.union_by_rank(2,4);
//     cout<<ds.find_ultimate_parent(3)<<endl;
//     cout<<ds.find_ultimate_parent(2);
// }

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;
    int n;

    DisjointSet(int N)
    {
        n = N;
        rank.resize(n,0);
        parent.resize(n);
        for(int i =0  ;i<n ; i++)
        {
            parent[i] = i;
        }
    }

    int find_ultimate_parent(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void union_by_rank(int u , int v)
    {
        int pu = find_ultimate_parent(u);
        int pv = find_ultimate_parent(v);

        if(pu == pv) return;
        else if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }

        else if(rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }

        else
        {
            parent[pu] = pv;;
            rank[pv]++;
        }
    }
};

int main()
{
    cout<<"Total Number of vertices : "<<endl;
    int V ; cin>>V;
    vector<int> adj[V];
    cout<<"Enter Total Number of Edges : "<<endl;
    int e ; cin>>e;
    vector<pair<int,pair<int,int>>> v;
    for(int i = 0 ; i<e ; i++)
    {
        cout<<"Enter Edge Wt : "<<endl;
        int wt ; cin>>wt;
        cout<<"Enter Starting Node : "<<endl;
        int sn ; cin>>sn;
        cout<<"Enter Ending Node : "<<endl;
        int en ; cin>>en;
        v.push_back({wt,{sn,en}});
    }

    sort(v.begin() , v.end());
    DisjointSet ds(V);
    int sum = 0;
    vector<pair<int,int>> ans;
    for(int i = 0 ; i<e ; i++)
    {
        int wt = v[i].first;
        int sn = v[i].second.first;
        int en = v[i].second.second;
        if(ds.find_ultimate_parent(sn) != ds.find_ultimate_parent(en))
        {
            sum += wt;
            ans.push_back({sn,en});
            ds.union_by_rank(sn,en);
        }
    }

    cout<<sum<<endl;
    for(auto it : ans)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

