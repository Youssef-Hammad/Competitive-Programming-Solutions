#include <bits/stdc++.h>
using namespace std;

const int N = 20;

long long n;

bool isValid(long long x)
{
    stringstream ss;
    ss << x;
    string st = ss.str();
    int cnt4 = 0,cnt7 = 0;
    for(int i = 0; i < st.size(); i++)
    {
        if(st[i] != '4' && st[i] != '7')
            return false;
        if(st[i]=='4')
            cnt4++;
        else
            cnt7++;
    }
    if(cnt4==cnt7)
        return true;
    return false;
}

int Size(long long x)
{
    stringstream ss;
    ss<<x;
    string st = ss.str();
    return st.size();
}

bool isLessThan(string temp,long long x)
{
    long long comp;
    stringstream ss(temp);
    ss>>comp;
    if(comp<x)
        return true;
    return false;
}

string createString(int sz)
{
    string ret = "";
    for(int i = 0; i < sz; i++)
    {
        if(i<sz/2)
            ret+='4';
        else
            ret+='7';
    }
    return ret;
}

bool isValidString(string s)
{
    int cnt4=0,cnt7=0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]=='4')
            cnt4++;
        else
            cnt7++;
    }
    return cnt4==cnt7;

}

string inc(string temp)
{
    int idx = temp.size()-1;
    while(true)
    {
        if(idx < 0)
        {
                temp = createString(temp.size()+2);
                break;
        }
        if(temp[idx] == '4')
        {
            temp[idx] = '7';
            if(isValidString(temp))
                break;
            else
            {
                idx = temp.size()-1;
                continue;
            }
        }
        else
        {
            temp[idx]='4';
        }
        idx--;
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    if(isValid(n))
        cout << n << endl;
    else
    {
        string temp;
        if(Size(n)%2 == 0)
            temp = createString(Size(n));
        else
            temp = createString(Size(n)+1);
        while(isLessThan(temp,n))
        {
            temp = inc(temp);
        }
        cout << temp << endl;
    }

    return 0;
}
