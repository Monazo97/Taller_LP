#include <bits/stdc++.h> 

using namespace std;

//~ Divide and conquer
 
//~ Merge Sort
//~ Potencia logaritmica
//~ Optimizacion DP

typedef long long ll;
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define pb push_back

ll power_log(ll a, ll b, ll m) { // O (log b)
  if(b == 0) return 1;
  ll p = power_log(a,b/2,m);
  ll ans = (p*p)%m;
  if(b%2 == 1) ans *= a, ans %= m;
  return ans; 
}

int main() {
  
  int n;
  cin >> n;
  while(n--) {
    ll a, b;
    cin >> a >> b;
    ll m = (ll)(1e9+7);
    cout << power_log(a,b,m) << "\n";
  }
  
  return 0; 
}
