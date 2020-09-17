#include <bits/stdc++.h>

using namespace std;
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back

//deque

const int MAXN = 200005;

vector <vector <pair<int,int> > > g(MAXN);

void BFS01(int start) {
  vector <bool> visto(MAXN,false);
  vector <int> dist(MAXN,10000000);
  deque <int> q;
  q.push_back(start); dist[start]=0;
  while(q.size() > 0) {
    int u = q.front(); q.pop_front();
    if(visto[u] == true) {
      continue;
    }
    visto[u] = true;
    for(pair<int,int> v : g[u]) {
      if(visto[v.first] == false) {
        dist[v.first] = min(dist[v.first],dist[u] + v.second);
        if(v.first == 1) {
          q.push_back(v.first);
        }
        else {
          q.push_front(v.first);
        }
      }
    }
  }
  return;
}

int main() {
  
  int n, m;
  //n nodos y m aristas
  cin >> n >> m;
  forn(i,m) {
    int x, y, z;
    // x nodo1, y nodo2, z peso (0 o 1)
    cin >> x >> y >> z;
    g[x].pb({y,z});
    g[y].pb({x,z});
  }
  //Nos piden la minima distancia desde cada nodo al nodo 1.
  BFS01(1);
  
  
  return 0;
}
