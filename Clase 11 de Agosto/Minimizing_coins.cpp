#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector <int> monedas(n);
  for(int i=0; i<n; i++) cin >> monedas[i];
  
  int INF = 100000000;
  vector <int> dp(k+5,INF);
  dp[0] = 0;
  
  for(int i=1; i<=k; i++) {
    for(int j=0; j<n; j++) {
      int u = monedas[j];
      if(i-u >= 0) dp[i] = min(dp[i],dp[i-u]+1);
    }
  }
  
  if(dp[k]==INF) {
    cout << "-1\n";
    return 0;
  }
  cout << dp[k] << "\n";

  return 0;
}
