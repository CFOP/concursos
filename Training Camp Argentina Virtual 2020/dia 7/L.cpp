#include <bits/stdc++.h>
using namespace std;

#define MAX 60

int t[MAX][MAX];
int n, m;

inline int cantidad(int x1, int y1, int x2, int y2){
  return t[x2][y2] - t[x2][y1-1] - t[x1-1][y2] + t[x1-1][y1-1];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin>>t[i][j];

  for(int i=1; i<=n; i++)
    for(int j=2; j<=m; j++){
      t[i][j]+=t[i][j-1];
    }

  for(int i=2; i<=n; i++)
    for(int j=1; j<=m; j++){
      t[i][j]+=t[i-1][j];
    }

  int a, b; cin>>a>>b;
  int minimo = INT32_MAX;
  a--, b--;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      if(i+a <= n && j+b <= m){
        minimo = min(minimo, cantidad(i,j,a+i, j+b));
      }
      if(i+b <= n && j+a <= m){
        minimo = min(minimo, cantidad(i,j,b+i, j+a));
      }
    }

  cout<<minimo<<"\n";


  return 0;
}

