#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;
 
int n,m,x,lang;
int emplang[N][N];
int parent[N];
int siz[N];
 
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!= b)
    {
        if(siz[a] < siz[b])
            swap(a,b);
        parent[b] = a;
        siz[a] +=b;
 
    }
}
 
void init()
{
    for(int i = 1; i <= n; i++)
        make_set(i);
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
    init();
    int zeros = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        if(!x)
        {
            zeros++;
            parent[i]=-1;
        }
        for(int j = 0; j < x; j++)
        {
            scanf("%d",&lang);
            emplang[i][lang]=1;
        }
    }
    for(int i = 1; i<= n; i++)
    {
        if(parent[i]==-1)
            continue;
        for(int j = i+1; j<=n; j++)
        {
            if(parent[j]==-1)
                continue;
            for(int k = 1; k<=m; k++)
            {
                if(emplang[j][k] == 1 && emplang[i][k] == 1)
                {
                    //printf("lol");
                    union_set(i,j);
                    break;
                }
            }
        }
    }
    set<int> ans;
    for(int i = 1; i<=n; i++)
        if(parent[i]!=-1)
            ans.insert(parent[i]);
        //printf("%d ",parent[i]);
    int anssize = ans.size();
    if(anssize)
        anssize--;
    printf("%d",anssize+zeros);
    return 0;
}
