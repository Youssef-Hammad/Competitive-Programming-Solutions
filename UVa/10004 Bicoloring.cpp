#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n,l;
int x,y;

vector<int> edges[N];

bool vis[N];
int col[N];

bool bfs(int src = 0)
{
    queue<int> q;
    q.push(src);
    col[src] = 1;
    vis[src] = true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        vis[temp]=true;
        for(int i = 0; i < edges[temp].size();i++)
        {
            if(col[temp]==col[edges[temp][i]])
                return false;
            if(!vis[edges[temp][i]])
            {
                q.push(edges[temp][i]);
                if(col[temp]==1)
                    col[edges[temp][i]]=2;
                else
                    col[edges[temp][i]]=1;
            }
        }
    }
    return true;
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

    while(cin >> n&&n)
    {
        cin >> l;
        for(int i = 0;i<n; i++)
            edges[i].clear();
        memset(col,0,sizeof col);
        memset(vis,false,sizeof vis);
        for(int i = 0; i <l; i++)
        {
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        cout << (bfs() ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }

    return 0;
}
