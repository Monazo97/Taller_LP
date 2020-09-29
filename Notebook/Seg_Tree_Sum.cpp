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
