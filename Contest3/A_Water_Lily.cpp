#include <bits/stdc++.h> 

using namespace std;

// https://codeforces.com/problemset/problem/1199/B

int main() {
  
  double h, l;
  cin >> h >> l;
  double ans;
  ans=((h*h+l*l)/2)/h-h;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
