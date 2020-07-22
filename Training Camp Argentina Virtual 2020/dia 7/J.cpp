#include <bits/stdc++.h>
using namespace std;

#define MAX 5005

int n, m;
long long T;
vector <pair<int, int>> g[MAX]; //costo, nodo
int padres[MAX];

vector <pair<int, int>> gInverso[MAX]; //costo, nodo

vector <int> recorrido;

int maximaCantidad, nodoMaximo;

long long minimo[MAX][MAX];// [nodo, nodos visitados] = minimo

int anterior(int v, int &maximaCantidad){
  maximaCantidad--;
  for(pair<int, int> p : gInverso[v]){
    int costo = p.first;
    int u = p.second;
    if(minimo[u][maximaCantidad]+costo == minimo[v][maximaCantidad+1]){
      return u;
    }
  }
  return 1;
}

int main(){
  cin>>n>>m>>T;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin>>u>>v>>w;
    g[u].push_back({w, v});
    gInverso[v].push_back({w, u});
    padres[v]++;
  }

  queue <int> next;
  next.push(1);


  while(next.size()){
    int actual = next.front();
    next.pop();
    //cout<<actual<<"\n";

    for(pair<int, int> arista : g[actual]){ //cada vecino
      int v = arista.second;
      int costo = arista.first;
      for(int i=1; i<=n; i++){ //cuantos nodos visitados
        if(minimo[actual][i] + costo > T) continue;
        if(minimo[actual][i] || (actual==1 && i==1)){ //es posible llegar a actual en i nodos
          if(!minimo[v][i+1]) minimo[v][i+1] = minimo[actual][i] + costo;
          minimo[v][i+1] = min(minimo[v][i+1], minimo[actual][i] + costo);
        }
      }
      padres[v]--;
      if(!padres[v]){
        next.push(v);
      }
    }


    //cout<<"\n\n";
  }

  for(int i=n; i>0; i--){
    //cout<<i<<" "<<minimo[n][i];
      //cout<<minimo[actual][i]<<" ";
      if(minimo[n][i]){
        maximaCantidad = i;
        nodoMaximo = n;
        break;
      }
    }
    //maximaCantidad = 4;
  cout<<maximaCantidad<<"\n";

  //reconstruir ;'v
  for(int v = nodoMaximo; v>1 ; v=anterior(v, maximaCantidad)){
    recorrido.push_back(v);
    //cout<<v<<" ";
  }
  recorrido.push_back(1);

  reverse(recorrido.begin(), recorrido.end());
  for(int v: recorrido)
    cout<<v<<" ";
  cout<<"\n";

  return 0;
}
