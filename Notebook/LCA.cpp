#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MAXN 300005
#define INF 1000000007
 
 
/* ---------------------------------------------------------------- */
 
//DFS
 
vector <int> v[MAXN], rv[MAXN];
vector <bool> visto(MAXN,false);
vector <int> first(MAXN,-1);
vector <int> lista, orden(MAXN,0), valor(MAXN,0);
vector <int> dp(MAXN,0);
 
int pos = 0;
 
void DFS(int n)
{
	first[n]=(int)lista.size();
	orden[n]=pos; valor[pos]=n; pos++;
	lista.pb(orden[n]);
	visto[n]=true;
	for(auto u : v[n])
	{
		if(!visto[u]) {dp[u]=dp[n]+1; DFS(u); lista.pb(orden[n]);} 
		
	}
}
 
 
 
/* ---------------------------------------------------------------- */
 
//Minimun Range Query
 
vector <int> tree(4*MAXN,0);
 
void actualizar(int pos)
{
	tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
}
 
int menor_segtree(int a, int b, int x, int y, int pos)
{
  if(x>b || y<a) return INF;
  if(x<=a && b<=y) return tree[pos];
  int med=(a+b)/2;
  return min(menor_segtree(a,med,x,y,2*pos+1),menor_segtree(med+1,b,x,y,2*pos+2));
}
 
void modificar_segtree(int a, int b, int pos, int y, int m)
{
  if(a==b) {tree[pos]=m; return;}
  int med=(a+b)/2;
  if(y<=med) modificar_segtree(a,med,2*pos+1,y,m);
  else modificar_segtree(med+1,b,2*pos+2,y,m);
  actualizar(pos);
}
 
void construir_segtree(int a, int b, int pos, vector <int> &v)
{
  if(a==b) {tree[pos]=v[a]; return;}
  int med=(a+b)/2;
  construir_segtree(a,med,2*pos+1,v);
  construir_segtree(med+1,b,2*pos+2,v);
  actualizar(pos);
}
 
void construir(vector <int> &v, int n)
{
	construir_segtree(0,n-1,0,v);
}
 
void modificar(int pos, int val, int n)
{
	modificar_segtree(0,n-1,0,pos,val);
}
 
int menor(int l, int r, int n)
{
	return menor_segtree(0,n-1,l,r,0);
}
 
/* ---------------------------------------------------------------- */
 
int LCA(int x, int y)
{
	int a = min(first[x],first[y]);
	int b = max(first[x],first[y]);
	//DBG(x); DBG(y); DBG(a); DBG(b); DBG(menor(a,b,lista.size())); RAYA;
	return valor[menor(a,b,lista.size())];
}
 
int main()
{ 
	FIN;
	
	#ifdef input
		freopen("test2.txt", "r", stdin);
	#endif
	
	int n, q;
	cin >> n >> q;
	forn(i,n-1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	DFS(0);
	
	construir(lista,lista.size());
	
	//forn(i,n) cout << dp[i] << " "; cout << endl; 
	//for(auto u : lista) cout << u << " "; cout << endl;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		cout << dp[a]+dp[b]-2*dp[LCA(a,b)] << endl;
	}
	
	return 0;
}
