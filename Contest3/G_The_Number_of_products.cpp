#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
 
 
int main()
{
	FIN;
	
  ll n;
  cin >> n;
  vector <ll> v(n);
  forn(i,n) cin >> v[i];
  ll contp = 0, contn = 0, contz = 0;
  forn(a,n) {
    if(v[a]==0) continue;
    int b = a;
    while(b+1<n && v[b+1]!=0) b++;
    vector < vector <ll> > dp(b-a+5,vector <ll> (2,0));
    if(v[a]>0) dp[0][1]=1;
    else dp[0][0]=1;
    for(int i = 1; i<=b-a; i++) {
      if(v[a+i]>0) {
        dp[i][1] = dp[i-1][1] + 1;
        dp[i][0] = dp[i-1][0];
      }
      else {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][1]+1;
      }
    }
    //forn(i,b-a+1) contp += dp[i][1];
    //forn(i,b-a+1) contn += dp[i][0];
    forn(i,b-a+1) contp += dp[i][1];
    forn(i,b-a+1) contn += dp[i][0];
    a=b;
  }
  contz = n*(n-1)/2 + n - contp - contn;
  cout << contn << " " << contz << " " << contp << " " << endl;
  
  return 0;
}
