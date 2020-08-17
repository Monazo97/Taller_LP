#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "============================" << endl

// https://codeforces.com/contest/1345/problem/B

int main() {
  
  int t;
  cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll ans = 0;
    while(n > 1) {
      ll a = 0, b = 1e5;
      while(b-a > 1) {
        ll med = (a+b)/2;
        ll cont = med*(med+1) + med*(med-1)/2;
        if(cont <= n) a=med;
        else b=med;
      }
      n-= a*(a+1) + a*(a-1)/2;
      ans++;
    }
    cout << ans << "\n"; 
  }
  
  
  return 0;
}
