#include <bits/stdc++.h>

using namespace std;

int main() {
  
  //freopen("pajaros.in", "r", stdin);
  //freopen("pajaros.out", "w", stdout);
  
  int n;
  cin >> n;
  vector <int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  
  int INF = (int)(1e9+7); 
  vector <int> dp_actual(305,INF), dp_vieja(305,INF);
  dp_vieja[0] = 0;
  
  for(int i=0; i<n; i++) {
    fill(dp_actual.begin(),dp_actual.end(),INF);
    for(int j=0; j<=300; j++) {
      if(j-1 >= 0) dp_actual[j] = min(dp_actual[j],dp_vieja[j-1] + abs(h[i]-j));
      if(j+1 <= 300) dp_actual[j] = min(dp_actual[j],dp_vieja[j+1] + abs(h[i]-j));
    }
    dp_vieja = dp_actual;
  }
  
  int ans = INF;
  for(int i = 0; i<=300; i++) ans = min(ans,dp_vieja[i]);
  
  cout << ans << "\n";
  
  
  return 0;
}
