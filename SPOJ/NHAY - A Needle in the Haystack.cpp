#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>,bool> piib;

const ll N=2e5+10;
const int MOD=1e9+7;

const ll M = 1e9 + 9, P = 9973;

ll pw[1000001]; // Stores the powers of P modulo M

int n;
string s1,s2;
ll hsh[1000001];
ll hsh2[1000001];

void init() {
  pw[0]=1;
  for(int i = 1;i<=100001;i++) {
    pw[i]=(pw[i-1]*P)%M;
  }
}

void calc_hashes() {
    hsh[0] = 1;

  int initp = 1;
  hsh[0]=s1[0]-'a';
  hsh2[0]=s2[0]-'a';
    for (int i = 0; i < s1.size(); i++)
        hsh[i + 1] = ((hsh[i] * P) % M + s1[i]) % M;
  for (int i = 0; i < s2.size(); i++)
        hsh2[i + 1] = ((hsh2[i] * P) % M + s2[i]) % M;

}


ll get_hash(int i, int j) { // Endpoints of the substring
    return (hsh[j + 1] - (hsh[i] * pw[j - i + 1]) % M + M) % M;
}

ll get_hash2(int i, int j) { // Endpoints of the substring
    return (hsh2[j + 1] - (hsh2[i] * pw[j - i + 1]) % M + M) % M;
}

int main() {

  //ios::sync_with_stdio(0);
  //cin.tie(NULL);
  //cout.tie(NULL);

  #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif // ONLINE_JUDGE	

  init();
  while(cin >> n) {
    cin >> s1 >> s2;
    //cout << s1 << " " << s2 << endl;
    calc_hashes();
    if(s2.size()<n)
      cout << "\n";
    else {
      int hash1 = get_hash(0,n-1);
      for(int i = 0; i < s2.size()-n+1; i++) {
        //cout << hash1 << " " << i << " " << get_hash2(i,i+n-1) << "\n";
        if(get_hash2(i,i+n-1)==hash1)
          cout << i << "\n";
      }
    }
  }

  return 0;
} 
