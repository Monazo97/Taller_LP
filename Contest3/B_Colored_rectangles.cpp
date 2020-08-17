#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// https://codeforces.com/contest/1398/problem/D
 
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
 
 
vector <ll> v1, v2, v3;
ll dp[205][205][205];
 
ll funcion(int r, int g, int b) {
  if(dp[r][g][b]!=-1) return dp[r][g][b];
  dp[r][g][b] = 0;
  if(r-1 >= 0 && g-1 >= 0) dp[r][g][b] = max(dp[r][g][b], funcion(r-1,g-1,b) + v1[r-1] * v2[g-1]); 
  if(r-1 >= 0 && b-1 >= 0) dp[r][g][b] = max(dp[r][g][b], funcion(r-1,g,b-1) + v1[r-1] * v3[b-1]);
  if(g-1 >= 0 && b-1 >= 0) dp[r][g][b] = max(dp[r][g][b], funcion(r,g-1,b-1) + v2[g-1] * v3[b-1]);
  return dp[r][g][b];
}
 
int main()
{
	FIN;
	
  int r, g, b;
  cin >> r >> g >> b;
  v1.resize(r);
  v2.resize(g);
  v3.resize(b);
  forn(i,r) cin >> v1[i];
  forn(i,g) cin >> v2[i];
  forn(i,b) cin >> v3[i];
  sort(all(v1));
  sort(all(v2));
  sort(all(v3));
  memset(dp,-1,sizeof(dp));
  ll ans = funcion(r,g,b);
  cout << ans << "\n";
  
  return 0;
}
