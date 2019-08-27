#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;
 
int t;
int n,m;
int str,stc;
char grid[N][N];
vector<pair<int,int> > cpos;
 
int ngrid[N][N];
 
bool isValid(int newi,int newj)
{
    return newi>= 0 && newi<n && newj>= 0 && newj<m && grid[newi][newj] != '#';
}
 
bool girlValid(int newi,int newj,int tim)
{
    return newi>= 0 && newi<n && newj>= 0 && newj<m && grid[newi][newj] != '#' && (ngrid[newi][newj] > tim);
}
 
int arr1[] = {0,0,1,-1};
int arr2[] = {1,-1,0,0};
 
struct node
{
    int x;
    int y;
    int level;
 
};
 
void cbfs()
{
    queue<node> q;
    bool vis[N][N];
    memset(vis,false,sizeof vis);
    for(int i = 0; i < cpos.size(); i++)
        q.push({cpos[i].first,cpos[i].second,0});
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int newi = cur.x+arr1[i];
            int newj = cur.y+arr2[i];
            if(isValid(newi,newj) && !vis[newi][newj])
            {
                q.push({newi,newj,cur.level+1});
                ngrid[newi][newj] = cur.level+1;
                vis[newi][newj] = true;
            }
        }
    }
}
 
void girlbfs(int r,int c)
{
    queue<node> q;
    bool vis[N][N];
    memset(vis,false,sizeof vis);
    vis[r][c] = true;
    q.push({r,c,0});
    bool flag = false;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int newi = cur.x+arr1[i];
            int newj = cur.y+arr2[i];
            //if(!vis[0][4])
                //cout << "valid" << endl;
            if(girlValid(newi,newj,cur.level+1) && !vis[newi][newj])
            {
                //cout << newi << " " << newj << " " <<cur.second+1 << endl;
                if(grid[newi][newj] == 'X')
                {
                    cout << "yes" << endl;
                    flag = true;
                    break;
                }
                q.push({newi,newj,cur.level+1});
                vis[newi][newj] = true;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout << "no" << endl;
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
 
    cin >> t;
    while(t--)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                ngrid[i][j]=1e9;
        cpos.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'S')
                {
                    str = i;
                    stc = j;
                }
                if(grid[i][j] == '*')
                    cpos.push_back({i,j});
            }
        }
        cbfs();
        girlbfs(str,stc);
    }
    /*for(int i = 0; i < n; i++)
        for(int j = 0; j<m; j++)
            cout << ngrid[i][j] << endl;*/
    return 0;
}
