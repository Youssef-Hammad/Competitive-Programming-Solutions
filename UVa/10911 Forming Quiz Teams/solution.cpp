#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n;

pair<int,int> arr[N];
double memo[100000];
string x;

double dist(int i, int j)
{
    return sqrt((arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second));
}

double dp(int mask)
{
    if(mask == (1<<2*n)-1)
        return 0;
    double &ret = memo[mask];
    if(ret == ret)
        return ret;
    ret = 1e9;
    for(int i = 0; i < 2*n; i++)
        for(int j = 0; j < 2*n; j++)
            if(i!=j)
                if((mask&(1<<j))==0 && (mask&(1<<i))==0)
                    ret = min(ret,dist(i,j)+dp(mask|(1<<j)|(1<<i)));
    return ret;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int test = 1;
    while(cin >> n && n)
    {
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < 2*n; i++)
        {
            cin >> x;
            cin >> arr[i].first >> arr[i].second;
        }
        cout << "Case " << test++ << ": " << fixed << setprecision(2) << dp(0) << endl;
    }
    return 0;
}
