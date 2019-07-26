#include <bits/stdc++.h>

using namespace std;

 

const int N = 1010;

vector<pair<int,int> > vec;

int t;

int n,g;

int x,y;

int memo[N][N];

int dp(int idx, int rem)

{

	if(idx == n)		return 0;

	int &ret = memo[idx][rem];

	if(~ret)

		return ret;

	ret = dp(idx+1,rem);

	if(vec[idx].second <= rem)

		ret = max(ret,dp(idx+1,rem-vec[idx].second)+vec[idx].first);

		

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

 

    cin >> t;

    while(t--)

    {

    	memset(memo,-1,sizeof memo);

    	vec.clear();

    	cin >> n;

    	long long ans = 0;

    	for(int i = 0; i < n; i++)

    	{

    		cin >> x >> y;

    		vec.push_back({x,y});

    	}

    	cin >> g;

    	for(int i = 0; i<g;i++)

    	{

    		cin >> x;

    		ans+=dp(0,x);

    	}

    	cout << ans << endl;

    }

    return 0;

}
