#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i<(int)n; i++)

const int MAXN = 100005;

vector < vector <int> > g(MAXN);
vector <bool> visto(MAXN,false);
vector <int> distancia(MAXN,-1);
vector <int> anterior(MAXN,-1);

// queue <int> --> permite pushearla al fondo cosas y permites sacar 
//                 el primer elemento.

void BFS(int start) {
  queue <int> q; 
  q.push(start);
  visto[start] = true;
  distancia[start] = 0;
  while(q.size() > 0) {
    int v = q.front(); q.pop();
    for(int u : g[v]) {
      if(visto[u] == false) {
        q.push(u);
        visto[u] = true;
        anterior[u] = v;
        distancia[u] = distancia[v] + 1;
      }
    } 
  } 
}

int main() {
  
  int n, m;
  cin >> n >> m;
  forn(i,m) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  BFS(0);
  if(visto[n-1] == false) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    cout << distancia[n-1]+1 << "\n";
    int pos = n-1;
    vector <int> recorrido; 
    while(anterior[pos] != -1) {
      recorrido.push_back(pos);
      pos = anterior[pos];
    }
    recorrido.push_back(0);
    reverse(recorrido.begin(),recorrido.end());
    for(int u : recorrido) cout << u+1 << " "; cout << "\n";
    
  }
  
  
  return 0;
}
