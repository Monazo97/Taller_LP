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

vector <ll> factorial(ll n, ll m) {
  vector <ll> ans;
  ans.pb(1);
  for(ll i = 1; i <= n; i++) {
    ans.pb((ans.back() * i)%m);
  }
  return ans;
}

ll inv_mod(ll x, ll m) {
  return power_log(x,m-2,m);
}

//~ O(n + log(p))

ll combinatorio(vector <ll> &f, ll n, ll k, ll m) {
  ll ans = 1;
  ans *= f[n];
  ans *= inv_mod(f[k],m); ans %= m;
  ans *= inv_mod(f[n-k],m); ans %= m;
  return ans;
}

int main() {
  
  ll a, b;
  cin >> a >> b;
  // Imprimir a+b-1 tomados de b
  //  (a+b-1)! 
  //  --------    * (b!) * inv_mod(b!) * (a-1)! * inv_mod((a-1)!)
  // (b!)*(a-1)!
  
  ll m = (ll)(1e9+7);
  vector <ll> f = factorial(a+b,m);
  ll ans = combinatorio(f,a+b-1,b,m);
  cout << ans << "\n";
  //forn(i,20) cout << f[i] << " "; cout << "\n";
  
  
  
  return 0; 
}
