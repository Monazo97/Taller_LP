#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i<(int)n; i++)

const int MAXN = 100005;

vector < vector <int> > g(MAXN);
vector <bool> visto(MAXN,false);

void DFS(int n, vector <int> &aux) {
  // n -> nodo actual en el que estoy
  // aux -> componente conexa en la que estoy
  aux.push_back(n);
  visto[n] = true;
  for(int u : g[n]) {
    if(visto[u] == false) {
      DFS(u,aux);
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
  
  /*
  forn(i,n) {
    cout << i+1 << ") ";
    for(int u : g[i]) cout << u+1 << " "; cout << "\n";
  }*/
  
  vector < vector <int> > componentes;
  
  forn(i,n) {
    if(visto[i] == false) {
      vector < int > aux; 
      DFS(i,aux);
      componentes.push_back(aux);
    }
  }
  
  /*
  forn(i,componentes.size()) {
    for(int u : componentes[i]) cout << u+1 << " "; cout << "\n";
  }*/
  
  cout << componentes.size()-1 << "\n";
  forn(i,componentes.size()-1) {
    cout << componentes[i][0]+1 << " " << componentes[i+1][0]+1 << "\n";
  }
  return 0;
}
