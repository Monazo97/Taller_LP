#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1e9+10); // (1e18+10)
const int MAXN = (int)(2e5+5);

// ^ Xor
// | Or
// & And
// << Agregame tantos 0 al final (multiplicar por 2^k)
// >> Sacame los ultimos k bits

struct jugo {
  int costo, mask = 0;
};

int solve(int pos, vector <int> &dp, vector <jugo> &v) {
  if(dp[pos] != -1) return dp[pos];
  dp[pos] = INF;
  for(jugo u : v) {
    dp[pos] = min(dp[pos], solve((pos|u.mask),dp,v) + u.costo);
  }
  return dp[pos];
}

int main(){
  FIN;
	
  int n; cin >> n;
  vector <jugo> v(n);
  forn(i,n) {
    string aux;
    cin >> v[i].costo >> aux;
    for(char u : aux) {
      v[i].mask |= 1<<(u-'A'); //'B'-'A'
    } 
  }
  // 2 1 0
  // 0 0 0
  // 0 0 1
  // 0 1 0
  // -----
  // 0 1 1 --> 3
  
  //~ for(jugo u : v) {
    //~ cout << u.costo << " " << u.mask << "\n";
  //~ }
  vector <int> dp(1<<3,-1);
  dp[(1<<3)-1] = 0; //dp[7]
  int ans = solve(0,dp,v);
  if(ans != INF) cout << ans << "\n";
  else cout << "-1\n";
	
  return 0;
}
