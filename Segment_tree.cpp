#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl

const int MAXN = 100005;

vector <ll> tree(4*MAXN);

void construir(int l, int r, int pos, vector <ll> &v) {
  if(l == r) {
    tree[pos] = v[l];
    return;
  }
  int med = (l+r)/2;
  construir(l,med,2*pos+1,v);
  construir(med+1,r,2*pos+2,v);
  tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

void modificar(int l, int r, int pos, int y, ll m) {
  if(l == r) {
    tree[pos] = m;
    return;
  }
  int med = (l+r)/2;
  if(y <= med) modificar(l,med,2*pos+1,y,m);
  else modificar(med+1,r,2*pos+2,y,m);
  tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

ll suma(int l, int r, int pos, int x, int y) {
  if(r < x || l > y) return 0;
  if(x <= l && y >= r) return tree[pos];
  int med = (l+r)/2;
  return suma(l,med,2*pos+1,x,y) + suma(med+1,r,2*pos+2,x,y);
}

int main() {
  
  int n, m;
  cin >> n >> m;
  vector <ll> v(n);
  forn(i,n) cin >> v[i];
  construir(0,n-1,0,v);
  //~ forn(i,2*n) cout << tree[i] << " "; cout << "\n";
  forn(i,m) {
    int x; cin >> x;
    if(x == 1) {
      int y; ll z;
      cin >> y >> z;
      // En la posicion y, ahora vale m
      modificar(0,n-1,0,y,z);
      //~ forn(i,2*n) cout << tree[i] << " "; cout << "\n";
    }
    else {
      // Hallar la suma en una dado intervalo
      int l, r;
      cin >> l >> r; r--;
      ll ans = suma(0,n-1,0,l,r);
      cout << ans << "\n";
    }
  }
  
  return 0;
}
