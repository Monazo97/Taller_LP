#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back

//deque

const int MAXN = 200005;

vector <vector <pair<int,ll> > > g(MAXN);

// O(V + E*log(E))
// V --> vertices
// E --> Edges (arista)

vector <ll> Dijkstra(int start) {
  vector <bool> visto(MAXN,false);
  vector <ll> dist(MAXN,10000000);
  set < pair<ll,int> > s;
  //Primer elemento --> distancia
  //Segundo elemento --> nodo
  s.insert({0,start});
  while(s.size() > 0) {
    pair<ll,int> u = *s.begin(); s.erase(s.begin());
    if(visto[u.second] == true) {
      continue;
    }
    visto[u.second] = true;
    dist[u.second] = u.first;
    for(pair<int,ll> v : g[u.second]) {
      if(visto[v.first] == false) {
        s.insert({dist[u.second]+v.second,v.first});
      }
    }
  }
  return dist;
}

int main() {
  
  int n, m;
  //n nodos y m aristas
  cin >> n >> m;
  forn(i,m) {
    int x, y;
    ll z;
    // x nodo1, y nodo2, z peso (0 o 1)
    cin >> x >> y >> z;
    g[x].pb({y,z});
    //g[y].pb({x,z});
  }
  //Nos piden la minima distancia desde cada nodo al nodo 1.
  vector <ll> ans = Dijkstra(1);
  forr(i,1,n+1) cout << ans[i] << " "; cout << "\n";
  
  
  return 0;
}
