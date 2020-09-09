#include <bits/stdc++.h> 

using namespace std;

#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)

const int MAXN = 1005;

vector <vector <bool> > visto(MAXN,vector<bool>(MAXN,false));

bool is_valid(int i, int j, int n, int m, vector <string> &v) {
  if(i>=0 && i<n && j>=0 && j<m && v[i][j] == '.') return true;
  else return false;
}

void DFS(int i, int j, int n, int m, vector <string> &v) {
  //~ i --> Fila y j --> Columna
  visto[i][j] = true;
  //~ if(is_valid(i,j-1,n,m,v) == true && visto[i][j-1]==false) DFS(i,j-1,n,m,v);
  //~ if(is_valid(i,j+1,n,m,v) == true && visto[i][j+1]==false) DFS(i,j+1,n,m,v);
  //~ if(is_valid(i-1,j,n,m,v) == true && visto[i-1][j]==false) DFS(i-1,j,n,m,v);
  //~ if(is_valid(i+1,j,n,m,v) == true && visto[i+1][j]==false) DFS(i+1,j,n,m,v);
  
  vector <int> move = {-1,0,1};
  
  for(int u : {-1,0,1}) {
    for(int w : {-1,0,1}) {
      if(abs(u)+abs(w) == 1) { 
        if(is_valid(i+u,j+w,n,m,v) == true && visto[i+u][j+w]==false) DFS(i+u,j+w,n,m,v);
      }
    }
  }
}

int main() {
  
  int n, m;
  cin >> n >> m;
  vector <string> v(n);
  forn(i,n) cin >> v[i];
  
  int ans = 0;
  
  forn(i,n) {
    forn(j,m) {
      if(v[i][j] == '.' && visto[i][j] == false) {
        DFS(i,j,n,m,v);
        ans++;
      } 
    }
  }
  cout << ans << "\n";
  
  return 0;
}
