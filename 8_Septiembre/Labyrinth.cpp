#include <bits/stdc++.h> 

using namespace std;

#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)

struct nodo {
  //~ i --> Fila
  //~ j --> columna
  //~ d --> distancia
  //~ move --> Ultimo movimiento realizado para llegar al nodo
  int i, j, d;
  char move;
};

struct punto {
  int x, y;
};

bool is_valid(int i, int j, int n, int m, vector <string> &v) {
  if(i>=0 && i<n && j>=0 && j<m && v[i][j]!='#') return true;
  else return false;
}

void debug(int i, int j, vector <vector <nodo> > &matriz) {
  cout << matriz[i][j].i << " " << matriz[i][j].j << " " << matriz[i][j].d << " " << matriz[i][j].move << "\n";
}

void BFS(punto start, punto end, int n, int m, vector <string> &v) {
  vector < vector <bool> > visto(n,vector<bool>(m,false));
  vector < vector <nodo> > matriz(n,vector<nodo>(m));
  queue <nodo> q;
  q.push({start.x,start.y,0,'Z'});
  matriz[start.x][start.y] = {start.x,start.y,0,'Z'};
  visto[start.x][start.y] = true; 
  
  while(q.size() > 0) {
    nodo u = q.front(); q.pop();
    if(is_valid(u.i,u.j-1,n,m,v)==true && visto[u.i][u.j-1]==false) {
      visto[u.i][u.j-1]=true;
      q.push({u.i,u.j-1,u.d+1,'L'});
      matriz[u.i][u.j-1] = {u.i,u.j-1,u.d+1,'L'};
    }
    if(is_valid(u.i,u.j+1,n,m,v)==true && visto[u.i][u.j+1]==false) {
      visto[u.i][u.j+1]=true;
      q.push({u.i,u.j+1,u.d+1,'R'});
      matriz[u.i][u.j+1] = {u.i,u.j+1,u.d+1,'R'};
    }
    if(is_valid(u.i-1,u.j,n,m,v)==true && visto[u.i-1][u.j]==false) {
      visto[u.i-1][u.j]=true;
      q.push({u.i-1,u.j,u.d+1,'U'});
      matriz[u.i-1][u.j] = {u.i-1,u.j,u.d+1,'U'};
    }
    if(is_valid(u.i+1,u.j,n,m,v)==true && visto[u.i+1][u.j]==false) {
      visto[u.i+1][u.j]=true;
      q.push({u.i+1,u.j,u.d+1,'D'});
      matriz[u.i+1][u.j] = {u.i+1,u.j,u.d+1,'D'};
    }
  }
  
  if(visto[end.x][end.y] == false) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    cout << matriz[end.x][end.y].d << "\n";
    string ans;
    nodo aux = matriz[end.x][end.y];
    while(aux.move != 'Z') {
      ans += aux.move;
      if(aux.move == 'U') aux = matriz[aux.i+1][aux.j];
      else if(aux.move == 'D') aux = matriz[aux.i-1][aux.j];
      else if(aux.move == 'R') aux = matriz[aux.i][aux.j-1];
      else if(aux.move == 'L') aux = matriz[aux.i][aux.j+1];
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
  }
  
} 

int main() {
  
  int n, m;
  cin >> n >> m;
  vector <string> v(n);
  forn(i,n) cin >> v[i];
  punto start, end;
  forn(i,n) {
    forn(j,m) {
      if(v[i][j] == 'A') start = {i,j};
      if(v[i][j] == 'B') end = {i,j};
    }
  }
  //~ cout << "Inicio: " << start.x << " ; " << start.y << "\n";
  //~ cout << "Fin: " << end.x << " ; " << end.y << "\n";
  
  BFS(start,end,n,m,v);
  
  return 0;
}
