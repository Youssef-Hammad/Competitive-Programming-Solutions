#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;

const ll N = 1e5+100;
const int MOD = 1e9+7;

ll n,a,b;

map<ll,ll> vis;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif


	while(cin>>n&&n)
	{
		vis.clear();
		cin>>a>>b;
		vis[0]=1;
		ll next=b%n;
		bool flag=false;
		ll cnt=0;
		while(vis[next]!=2)
		{
			ll &cur = vis[next];
			cur++;
			if(cur==2)
			{
				flag=true;
				cnt++;
			}
			next=(a*((next*next)%n)+b)%n;
		}
		cout << n-cnt << endl;
	}
	
	
}
