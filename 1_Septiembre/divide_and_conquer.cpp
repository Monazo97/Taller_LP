#include <bits/stdc++.h> 

using namespace std;

//~ Divide and conquer
 
//~ Merge Sort
//~ Potencia logaritmica
//~ Optimizacion DP

#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define pb push_back

vector <int> merge_sort(vector <int> &v, int l, int r) {
  //~ l -> left, r->rigth
  if(l == r) {
    vector <int> ans;
    ans.pb(v[l]);
    return ans;
  }
  int med = (l+r)/2;
  //~ Resolvemos el problema para el intervalo [l,med],[med+1,r] 
  vector <int> left = merge_sort(v,l,med);
  vector <int> rigth = merge_sort(v,med+1,r);
  int p1 = 0, p2 = 0;
  vector <int> ans; 
  while(p1 < left.size() && p2 < rigth.size()) {
    if(left[p1] <= rigth[p2]) ans.pb(left[p1]), p1++;
    else ans.pb(rigth[p2]), p2++;
  }
  while(p1 < left.size()) ans.pb(left[p1]), p1++;
  while(p2 < rigth.size()) ans.pb(rigth[p2]), p2++;
  return ans;
}

int main() {
  
  int n; cin >> n;
  vector <int> v(n);
  forn(i,n) cin >> v[i];
  sort(v.begin(),v.end()); // O (n * log(n) )
  //for(int u : v) cout << u << " "; cout << "\n";
  
  vector <int> ans = merge_sort(v,0,n-1);
  for(int u : ans) cout << u << " "; cout << "\n";
  
  return 0; 
}
