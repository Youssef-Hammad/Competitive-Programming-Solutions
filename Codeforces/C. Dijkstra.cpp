#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+10;
 
long long dist[N];
int parent[N];
 
struct edge
{
    int to;
    long long cost;
    bool operator<(const edge &other) const
    {
        return cost>other.cost;
    }
};
 
vector<edge> adj[N];
int n,m;
 
void dijkstra(int src = 0)
{
    fill(dist,dist+N,1e18);
    memset(parent,-1,sizeof parent);
    dist[src] = 0;
    priority_queue<edge> pq;
    pq.push({src,0});
    while(!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        int u = e.to;
        long long uCost = e.cost;
 
        if(dist[u]<uCost)
            continue;
 
        for(int i = 0; i < adj[u].size();i++)
        {
            int v = adj[u][i].to;
            long long c = adj[u][i].cost;
            if(dist[v]>dist[u]+c)
            {
                dist[v]=dist[u]+c;
                pq.push({v,dist[v]});
                parent[v] = u;
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
 
    scanf("%d%d",&n,&m);
    int x,y,w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    dijkstra(1);
    int i = n;
    vector<int> ans;
    while(parent[i]!=-1)
    {
        ans.push_back(i);
        i = parent[i];
    }
    if(ans.size() == 0)
    {
        printf("-1");
        return 0;
    }
    printf("1 ");
    for(int i = ans.size()-1; i >=0; i--)
        printf("%d ",ans[i]);
 
    return 0;
}