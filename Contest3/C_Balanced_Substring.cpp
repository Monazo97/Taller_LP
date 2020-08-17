#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/873/problem/B

int main() {
  int n; cin >> n;
  string pal; cin >> pal;
  vector <int> first_pos(100005,-1), first_neg(100005,-1);
  int ans = 0, suma = 0; first_pos[0] = 0;
  for(int i=0; i<n; i++) {
    int aux = pal[i]-'0'; if(aux == 0) aux--;
    suma += aux;
    if(suma >= 0) {
      if(first_pos[suma] != -1) ans = max(ans, i+1-first_pos[suma]); 
      else first_pos[suma] = i+1;
    }
    else {
      if(first_neg[abs(suma)] != -1) ans = max(ans, i+1-first_neg[abs(suma)]);
      else first_neg[abs(suma)] = i+1;
    }
    
  }
  cout << ans << "\n";
  
  return 0;
}
