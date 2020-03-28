//https://codeforces.com/contest/357/problem/C
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;
 
const ll N = 3*1e5+10;
const ll INF = 1e9;
const ll N2 = 1010;
const int MOD = 1e9+7;

int hi[4*N];
int lo[4*N];
int mn[4*N];
int delta[4*N];
int n,m;

void build(int i,int a,int b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	int mid = (a+b)/2;
	build(2*i,a,mid);
	build(2*i+1,mid+1,b);
}

void propagate(int i)
{
	delta[2*i]=min(delta[i],delta[2*i]);
	delta[2*i+1]=min(delta[i],delta[2*i+1]);
	//delta[i]=0;
}

void update(int i)
{
	mn[i] = min(min(mn[2*i],delta[2*i]),min(mn[2*i+1],delta[2*i+1]));
}



void upd(int i,int a,int b, int val)
{

	if(b<lo[i]||hi[i]<a)
		return;
	if(a<=lo[i]&&hi[i]<=b)
	{
		delta[i]=min(delta[i],val);
		return;
	}

	//Partial cover case
	propagate(i);

	upd(2*i,a,b,val);
	upd(2*i+1,a,b,val);

	update(i);
}

void upd(int i,int j,int val)
{
	upd(1,i,j,val);
}



int getMin(int i,int a,int b)
{
	if(b<lo[i]||hi[i]<a)
		return INF;
	if(a<=lo[i]&&hi[i]<=b)
		return mn[i]+delta[i];

	propagate(i);

	int minLeft = getMin(2*i,a,b);
	int minRight = getMin(2*i+1,a,b);

	update(i);

	return min(minLeft,minRight);
}

int getMin(int i,int j)
{
	return getMin(1,i,j);
}

int roundWinners[N];
int x,y,winner;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	cin >> n>>m;
	build(1,1,n);
	for(int i = 1; i <= 4*n+1; i++)
		delta[i]=INF;
	for(int i = 1; i <= m; i++)
	{
		cin >> x >> y >> winner;
		roundWinners[i]=winner;
		if(winner==x)
			upd(x+1,y,i);
		else if(winner==y)
			upd(x,y-1,i);
		else
		{
			upd(x,winner-1,i);
			upd(winner+1,y,i);
		}
		
	}
	for(int i = 1; i<= n; i++)
	{
		int win = getMin(i,i);
		if(win==INF)
			cout << "0 ";
		else
			cout << roundWinners[win] << " ";
		
	}
	

}
