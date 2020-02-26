#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N = 1<<31;

int n,m,x;

vector<ll> primes;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
ll findlcm(vector<ll> arr) 
{ 
    ll ans = arr[0]; 
  
    for (int i = 1; i < arr.size(); i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 


pair<ll,ll> getMult(int msk)
{
	pair<ll,ll> ret;
	ret={1,0};
	int tmp=msk;
	int idx=primes.size()-1;
	vector<ll> nums;
	while(tmp)
	{
		if(tmp%2)
		{
			ret.second++;
			nums.push_back(primes[idx]);
		}
		tmp/=2;
		idx--;
	}
	ret.first=findlcm(nums);
	return ret;
}

ll solve()
{
	int msk;
	ll ans=0;
	pair<ll,ll> tmp;
	for(msk=1;msk<(1<<primes.size());msk++)
	{
		tmp=getMult(msk);
		//cout<<tmp.first<<" "<<tmp.second<<endl;
		if(tmp.second%2)
			ans+=n/tmp.first;
		else
			ans-=n/tmp.first;
	}
	return ans;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    
    while(cin>>n>>m)
    {
    	primes.clear();
    	for(int i=0;i<m;i++)
    	{
    		cin>>x;
    		primes.push_back(x);
    	}
    	for(int i=0;i<primes.size();i++)
    	{
    		for(int j=0;j<primes.size();j++)
    			if(i!=j)
    				if(primes[j]%primes[i]==0)
    				{	primes.erase(primes.begin()+j--);
    				if(i>=j)
    					i--;
    				}
   	 } 
    	ll num= solve();
    	//cout<<num<<endl;
    	cout<<n-num<<endl;
    }

}
