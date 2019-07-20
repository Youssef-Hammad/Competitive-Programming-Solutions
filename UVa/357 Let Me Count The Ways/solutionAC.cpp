#include <bits/stdc++.h>
using namespace std;

const int N = 30010;

int n;
int arr[] = {1,5,10,25,50};
long long memo[5][N];

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
        memset(memo,0,sizeof memo);
        memo[0][0]=1;
        for(int i = 0; i<5; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                if(i)
                    memo[i][j]+=memo[i-1][j];
                if(j>=arr[i])
                    memo[i][j]+=memo[i][j-arr[i]];
            }
        }
        long long ans = memo[4][n];
        if(ans != 1)
            cout << "There are "<<ans<<" ways to produce "<<n<<" cents change." << endl;
        else
            cout << "There is only 1 way to produce "<<n<<" cents change." << endl;
    }

    return 0;
}
