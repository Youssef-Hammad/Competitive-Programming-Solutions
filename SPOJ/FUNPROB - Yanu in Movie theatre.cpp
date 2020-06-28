#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=1001;
const int MOD=1e9+7;

int n,m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("mosalah.in","r",stdin);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while(cin>>n>>m && (m||n))
    {
        if(n>m)
            cout << "0.000000" << endl;
        else
        {
            cout << fixed << setprecision(6) << double(m-n+1)/(m+1) << endl;
        }
        
    }
    return 0;
}