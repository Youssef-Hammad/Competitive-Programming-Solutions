#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;

const ll N = 20000;
const ll N2 = 1010;
const int MOD = 1e9+7;

int t;

int n,m;
string arr[N][N2];

ll ans[N][N2];

bool vis[N][N2];

ll conv(string s)
{
	ll ret;
	stringstream ss(s);
	ss>>ret;
	return ret;
}

vector<string> cut(string s)
{
	vector<string> ret;
	string temp;
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i]=='+')
		{
			ret.push_back(temp);
			temp="";
		}
		else
			temp+=s[i];
	}
	ret.push_back(temp);
/*	for(int i = 0; i < ret.size(); i++)
		cout << ret[i]<<endl;*/
	return ret;
}

pll getIdx(string s)
{
	string letters;
	pll ret = {0,0};
	int i = 0;
	for(; i < s.size()&&s[i]>='A'&&s[i]<='Z';i++)
		letters+=s[i];
	ll cur = 1;
	for(int k = letters.size()-1; k>=0; k--)
	{
		ret.second+=((letters[k]-'A')+1)*cur;
		cur*=26;
	}
	cur=1;
	for(int k = s.size()-1; k>=i; k--)
	{
		ret.first+=(s[k]-'0')*cur;
		cur*=10;
	}
	return ret;

}

ll dfs(pll idx)
{
	if(vis[idx.first][idx.second])
		return ans[idx.first][idx.second];
	vis[idx.first][idx.second]=true;
	vector<string> str = cut(arr[idx.first][idx.second]);
	for(int k = 0; k < str.size(); k++)
	{
		//cout << ans[idx.first][idx.second]<<endl;
		ans[idx.first][idx.second]+=dfs(getIdx(str[k]));
	}

	return ans[idx.first][idx.second];
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

	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof vis);
		memset(ans,0,sizeof ans);
		cin >> m>>n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> arr[i][j];
				if(arr[i][j][0]!='=')
				{
					ans[i][j]=conv(arr[i][j]);
					vis[i][j]=true;
				}
			}
		}
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<= m; j++)
				if(!vis[i][j])
					dfs({i,j});
		for(int i = 1; i<= n; i++)
		{
			for(int j = 1; j<= m; j++)
			{
				cout << ans[i][j];
				if(j!=m)
					cout<<" ";
			}
			cout << endl;
		}

	}
	
	
}


