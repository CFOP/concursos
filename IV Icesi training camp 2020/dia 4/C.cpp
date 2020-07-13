///Codigo de Luis y corregido por Yoguel
#include<bits/stdc++.h>
#define ll long long
#define MAX 100001
using namespace std;

ll n, m;
vector<pair<ll, ll> >ady[MAX];
bool visitado[MAX];
ll camino[MAX];
ll dist[MAX];

void dijkstra(ll nodo){
    set<pair<ll, ll> > Cola;
    Cola.insert({0, nodo});
    dist[nodo] = 0;
    camino[nodo] = nodo;
    while(Cola.size()){

        nodo = (*Cola.begin()).second;
        ll peso = (*Cola.begin()).first;
        Cola.erase(*Cola.begin());

        if(!visitado[nodo]){
            visitado[nodo] = 1;
            for(auto i : ady[nodo]){
                ll v = i.first;
                if (!visitado[v] && dist[v] > dist[nodo] + i.second){
                    dist[v] = dist[nodo] + i.second;
                    camino[v] = nodo;
                    Cola.insert({dist[v], v});
                }
            }
        }
    }
    if(dist[n] == LLONG_MAX){
        cout<<-1<<"\n";
        return;
    }
    vector<ll>aux;
    while(n != camino[n]){
        aux.push_back(n);
        n = camino[n];
    }
    reverse(aux.begin(), aux.end());
    cout<<"1 ";
    for(auto i : aux)
        cout<<i<<" ";
    cout<<"\n";
}

void init(){
    for (ll i = 0; i < MAX; i++){
        dist[i] = LLONG_MAX;
        visitado[i] = false;
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    init();

    cin>>n>>m;

    while(m--){
        ll a, b, w;
        cin>>a>>b>>w;
        ady[a].push_back({b, w});
        ady[b].push_back({a, w});
    }

    dijkstra(1);
}
