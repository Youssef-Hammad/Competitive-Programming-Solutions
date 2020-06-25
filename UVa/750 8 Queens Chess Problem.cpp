#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=200;
const int MOD=1e9+7;

int t;
int stx,sty;

bool valid(int arr[8])
{
	int curx,cury;
	for(int i = 0; i <8; i++)
	{
		curx = arr[i], cury=i+1;
		for(int j = 0; j < 8; j++)
		{
			if(i!=j)
			{
				//if((curx-cury == (j+1)-arr[j]))
				//	return false;
				if(abs(cury-(j+1))==abs(curx-arr[j]))
					return false;
			}
		}
	}
	return true;
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
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		
		cin >> stx >> sty;
		int arr[7];
		int idx = 0;
		int cur = 1;
		for(int i = 1; i<=8; i++)
		{
			if(i!=sty)
			{
				if(cur!=stx)
					arr[idx++]=cur++;
				else
				{
					i--;
					cur++;
				}
			}	
		}
		int solnum = 1;
		do {
			idx=0;
			int newarr[8];
			for(int i = 1; i<=8; i++)
			{
				if(i==sty)
					newarr[i-1]=stx;
				else
					newarr[i-1]=arr[idx++];
			}
			if(valid(newarr))
				{
					cout << setw(2) << solnum++ << "      ";
					for(int i = 0; i < 8; i++)
					{
						cout << newarr[i];
						if(i!=7)
							cout << " ";
					} 
					cout << endl;
				}
		} while(next_permutation(arr,arr+7));
		if(t)
			cout << endl;
	}
}
