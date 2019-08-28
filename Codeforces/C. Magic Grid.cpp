#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3+10;
 
int n;
int ans[N][N];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
 
    scanf("%d",&n);
    ans[0][0] = 0;
    ans[0][1] = 15;
    ans[0][2] = 1;
    ans[0][3] = 14;
 
    for(int i = 4; i<n; i++)
        ans[0][i] = ans[0][i-4]+16;
 
    for(int i = 1; i<n; i++)
    {
        if(i%4)
        {
            if(i%2)
            {
                ans[i][0] = ans[i-1][3]-1;
                ans[i][1] = ans[i-1][2]+1;
                ans[i][2] = ans[i][0]-1;
                ans[i][3] = ans[i][1]+1;
            }
            else
            {
                ans[i][0] = ans[i-1][3]+1;
                ans[i][1] = ans[i-1][2]-1;
                ans[i][2] = ans[i][0]+1;
                ans[i][3] = ans[i][1]-1;
            }
        }
        else
        {
            ans[i][0] = ans[i-4][n-3]+1;
            ans[i][1] = ans[i][0]+15;
            ans[i][2] = ans[i][0]+1;
            ans[i][3] = ans[i][1]-1;
        }
        for(int j = 4; j<n; j++)
                ans[i][j] = ans[i][j-4]+16;
    }
    for(int i = 0;i<n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
