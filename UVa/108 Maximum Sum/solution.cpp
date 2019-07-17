#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int grid[N][N];
int sum[N];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while(cin >> n)
    {
        int mx = -1e9;
        int mxel = -1e9;
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                mxel = max(mxel,grid[i][j]);
            }
        }
        for(int k = 0; k < n; k++)
        {
            memset(sum,0,sizeof sum);
            for(int j = k; j < n; j++)
            {
                cur = 0;
                for(int i = 0; i < n; i++)
                    sum[i]+=grid[i][j];
                for(int j = 0; j < n; j++)
                {
                    cur+=sum[j];
                    cur = max(cur,0);
                    mx = max(mx,cur);
                }
            }
        }
        if(mx)
            cout << mx << endl;
        else
            cout << mxel << endl;
    }



    return 0;
}
