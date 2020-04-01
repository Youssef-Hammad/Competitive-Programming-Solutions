#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n";
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;
 
const ll N = 110;
const ll INF = 1e9;
const ll N2 = 1010;
const int MOD = 1e9+7;

int n,k;
int arr[N]; //black = 1, white = 0

vector<int> graph[N];

vector<int> bestBlacks,curBlacks;

bool canBeBlack(int node)
{
    for(int i = 0; i < graph[node].size(); i++)
    {
        if(arr[graph[node][i]] || graph[node][i]==node)
            return false;
    }
    return true;
}

void backTrack(int cur)
{
    if(bestBlacks.size() < curBlacks.size())
            bestBlacks = curBlacks;
    if(cur == n+1)
        return;
    int maxBlacks = (n+1)-cur;
    if(maxBlacks+curBlacks.size()<=bestBlacks.size())
        return;
    
    for(int i = cur; i<= n; i++)
    {
        if(canBeBlack(i))
        {
            arr[i]=1;
            curBlacks.push_back(i);

            backTrack(i+1);

            curBlacks.pop_back();
            arr[i]=0;
        }
    }
}

int x,y;

void init()
{
    memset(arr,0,sizeof arr);
    bestBlacks.clear();
    curBlacks.clear();
    for(int i = 0; i < N;i++)
        graph[i].clear();
}

int main()
{
	fastio
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

    int t;
    cin >> t;
    while(t--)
    {
        init();
        cin >> n >> k;
        for(int i = 0; i<k; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        backTrack(1);
        cout << bestBlacks.size() << endl;
        for(int i = 0; i < bestBlacks.size(); i++)
        {
            cout << bestBlacks[i];
            if(i!=bestBlacks.size()-1)
                cout << " ";
        }
        cout << endl;
    }
	

}
