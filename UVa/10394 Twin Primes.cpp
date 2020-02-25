#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<int,int>,bool> piib;

const int N = 2e7;


int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

bool arr[N];
int n;

void sieve(int num)
{
	int x = num*2;
	while(x<N)
	{
		arr[x]=true;
		x+=num;
	}
}

vector<pll> twins(1000000);
ll lastPrime=0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	int idx=0;

	for(int i = 3; i < N; i+=2)
	{
		if(!arr[i])
		{
			sieve(i);
			if(i-lastPrime==2)
				twins[idx++]={lastPrime,i};
			lastPrime=i;
		}
	}
	
	while(cin>>n)
		cout<<"("<<twins[n-1].first<<", "<<twins[n-1].second<<")"<<endl;

}
