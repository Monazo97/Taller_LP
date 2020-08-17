#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1213/problem/A

int main() {
  
  int n; cin >> n;
  vector <int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  int par = 0, impar = 0;
  for(int u : v) {
    if(u%2 == 0) par++;
    else impar++;
  }
  cout << min(impar,par) << "\n";
  return 0;
}
