#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=200;
const int MOD=1e9+7;

vector<int> vec(5);
char op[] = {'+','-','*'};

bool valid()
{
	for(int i = 0; i < 5; i++)
		if(vec[i]>0)
			return true;
	return false;
}

int eval(int arr[9])
{
	int ans = vec[arr[0]];
	for(int i = 0; i < 8; i+=2)
	{
		if(op[arr[i+1]]=='+')
			ans+=vec[arr[i+2]];
		else if(op[arr[i+1]]=='-')
			ans-=vec[arr[i+2]];
		else
			ans*=vec[arr[i+2]];
	}
	//cout << ans << endl;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(	cin >> vec[0] >> vec[1] >> vec[2] >> vec[3] >> vec[4] && valid())
	{
		bool flag = false;
		int arr[9];
		for(int a1 = 0; a1<5; a1++)
		{
			for(int op1 = 0; op1<3; op1++)
			{
				for(int a2 = 0; a2<5; a2++)
				{
					if(a2==a1)
						continue;
					for(int op2 = 0; op2<3; op2++)
					{
						for(int a3 = 0; a3<5; a3++)
						{
							if(a3==a2||a3==a1)
								continue;
							for(int op3 = 0; op3<3; op3++)
							{
								for(int a4 = 0; a4<5; a4++)
								{
									if(a4==a3||a4==a2||a4==a1)
										continue;
									for(int op4 = 0; op4<3; op4++)
									{
										for(int a5 = 0; a5<5; a5++)
										{
											if(a5==a4||a5==a3||a5==a2||a5==a1)
												continue;
											arr[0]=a1;
											arr[1]=op1;
											arr[2]=a2;
											arr[3]=op2;
											arr[4]=a3;
											arr[5]=op3;
											arr[6]=a4;
											arr[7]=op4;
											arr[8]=a5;
											if(eval(arr)==23)
											{
												cout << "Possible" << "\n";
												flag = true;
												break;
											}
										}
										if(flag)
											break;
									}
									if(flag)
										break;
								}
								if(flag)
									break;
							}
							if(flag)
								break;
						}
						if(flag)
							break;
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(!flag)
			cout << "Impossible" << "\n";
	}
}
