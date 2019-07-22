#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int t;

int n,m,k;

int grid[N][N];

int sum[N];

int slidingWindow(int j,int curd)

{

    int l=0,r=0,s=0;

    int mxSummation = -1;

    int mxSummationL = -1, mxSummationR = -1;

    while(l<n)

    {

        while(r<n&& s+sum[r]<=k) s+=sum[r],r++;

        if(mxSummationR-mxSummationL < r-l)

        {

          mxSummationR = r;

          mxSummationL = l;

        }

        s-=sum[l];

        l++;

    }

   // cout << mxSummationL << " " << mxSummationR << endl << curd << " " << j << endl;

    return (mxSummationR-mxSummationL)*(j-curd+1);

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

        int ans = 0;

        cin >> n >> m >> k;

        for(int i = 0; i < n; i++)

            for(int j = 0; j < m; j++)

                cin >> grid[i][j];

        for(int d = 0; d < m; d++)

        {

            memset(sum,0,sizeof sum);

            for(int j = d; j<m; j++)

            {

                for(int i = 0; i < n; i++)

                    sum[i]+=grid[i][j];

                ans = max(ans,slidingWindow(j,d));

            }

        }

        cout << ans << endl;

    }

    return 0;

}
