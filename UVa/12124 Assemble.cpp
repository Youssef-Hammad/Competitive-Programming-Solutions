#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=1001;
const int MOD=1e9+7;

int t;
int n,b;
string dummy1,dummy2;
int price,quality;
int sz;

map<string,int> type;

vector<pair<int,int> > arr[N];

bool valid(ll num)
{
    ll curprice = 0;
    ll mn=1e16;
    for(int i = 0; i < sz; i++)
    {
        mn = 1e16;
        for(int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j].first>=num&&mn>arr[i][j].second)
                mn=arr[i][j].second;
        }

        curprice+=mn;
    }
    return curprice<=b;
}

ll bs()
{
    ll st=0,en=1e9;
    ll mid;
    ll ans = 0;
    while(st<en)
    {
        mid = st+(en-st+1)/2;
        //cout << mid << endl;
        if(mid&&valid(mid))
        {
            st=mid;
            ans=mid;
        }
        else
            en=mid-1;
    }
    return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

	cin >> t;
	while(t--)
	{
		cin >> n >> b;
		type.clear();
        sz=0;
		for(int i = 0; i < N; i++)
			arr[i].clear();
		for(int i = 0; i < n; i++)
		{
			cin >> dummy1 >> dummy2 >> price >> quality;
			if(type.find(dummy1)==type.end())
				type[dummy1] = sz++;
			arr[type[dummy1]].push_back({quality,price});
		}
		for(int i = 0; i < sz; i++)
			sort(arr[i].begin(), arr[i].end());
		cout << bs() << endl;
	}

	
}
