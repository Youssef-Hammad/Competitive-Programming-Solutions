#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=200;
const int MOD=1e9+7;

ll t;
ll n,k;
ll x;
vector<ll> vec;

bool valid(ll num)
{
    ll temp=k;
    for(int i = 0; i < n&&temp>0; i++)
    {
        if(vec[i]<num)
            return false;
        else
        {
            temp-=(vec[i]/num);
        }
    }
    if(temp>0)
        return false;
    return true;
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
	
    cin >> t;
    while(t--)
    {
        vec.clear();
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.rbegin(), vec.rend());

        cout << bs() << "\n";
    }
	
}
