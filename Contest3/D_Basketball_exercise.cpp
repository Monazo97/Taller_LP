#include <bits/stdc++.h> 

using namespace std;

// https://codeforces.com/problemset/problem/1195/C

int main() {
  
  int n; cin >> n;
  vector <long long> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  
  long long dp1, dp2;
  dp1 = a[0]; dp2 = b[0];
  for(int i =1; i<n; i++) {
    long long aux = dp2 + a[i];
    long long aux2 = dp1 + b[i];
    dp1 = max(dp1,aux);
    dp2 = max(dp2,aux2);
  } 
  cout << max(dp1,dp2) << "\n";
  return 0;
}
