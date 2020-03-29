//https://codeforces.com/contest/357/problem/C
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n";
#define fastio  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;
 
const ll N = 3*1e5+10;
const ll INF = 1e9;
const ll N2 = 1010;
const int MOD = 1e9+7;

ll p,d;

ll getNines(ll num)
{
    ll ret = 1;
    for(int i = 1; i<=num; i++)
        ret*=10;
    return ret-1;
}
 
int main()
{
	fastio
	
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

    cin >> p >> d;

    if(!d||p<10)
    {
        cout << p;
        return 0;
    }

    ll cur = 10;
    int pw=1;
    ll ans=p%cur;
    ll curpw=1;
    bool first = true;
    while(cur<p)
    {
        ll temp=p%cur;
        if(temp!=getNines(pw))
        {
            if(temp+1 > d)
            {
                if(first)
                {
                    cout << p << endl;   
                    return 0;
                }
                break;

            }
            ans=temp;
            curpw=pw;
        }
        pw++;
        cur*=10;
        first = false;
    }
    ll temp = getNines(curpw);
    if(temp==ans)
        cout << p;
    else
        cout << p-(ans+1);

}
