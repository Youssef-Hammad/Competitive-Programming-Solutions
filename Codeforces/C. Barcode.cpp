#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int n,m,x,y;
char grid[N][N];
int beBlack[N],beWhite[N];

int memo[N][N][2];

///colour 1 = black, 0 = white

int dp(int idx,int cnt,int colour)
{
    if(cnt>y)
        return 1e9;
    if(idx == m)
        return (cnt>=x && cnt<=y ? 0 : 1e9);
    int &ret = memo[idx][cnt][colour];
    if(~ret)
        return ret;
    ret = 1e9;
    ret = min(ret,dp(idx+1,cnt+1,colour)+(colour ? beBlack[idx] : beWhite[idx]));
    if(cnt>=x)
        ret = min(ret,dp(idx+1,1,colour^1)+(colour ? beWhite[idx] : beBlack[idx]));
    return ret;
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

    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c",&grid[i][j]);
    for(int j = 0; j < m; j++)
    {
        int wcnt=0,bcnt=0;
        for(int i=0; i<n; i++)
        {
            if(grid[i][j]=='.')
                wcnt++;
            else
                bcnt++;
        }
        beBlack[j]=wcnt;
        beWhite[j]=bcnt;
    }
    memset(memo,-1,sizeof memo);
    printf("%d",min(dp(0,0,0),dp(0,0,1)));
    return 0;
}
