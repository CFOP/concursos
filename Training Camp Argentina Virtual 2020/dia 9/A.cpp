#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

vector <int> g[MAX];
bool visitado[MAX];
long long black, white;

void contar(int v, bool b){
  if(visitado[v])
    return;
  visitado[v]=true;

  if(b)
    black++;
  else
    white++;

  for(int u : g[v])
    contar(u, !b);
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  //n--;
  for(int i=1; i<n; i++){
    int u, v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  contar(1, true);

  //cout<<black<<" "<<white<<"\n";
  cout<< (long long)black*white - (long long)(n-1)<<"\n";

  return 0;
}
