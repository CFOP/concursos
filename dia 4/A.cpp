#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int n, k;
vector<int> v[MAX]; // MAX aristas.
pair <int, int> vertice[MAX]; //altura, ID
long long felicidad[MAX];
bool esIndustria[MAX];

#define altura first
#define ID second

int calcularAltura(int i, int alturaActual){
    if(vertice[i].altura)
        return 0;
    vertice[i].altura = alturaActual;
    vertice[i].ID = i;
    int hijos = 0;
    for(int u : v[i]){
        hijos += calcularAltura(u, alturaActual+1);
    }
    vertice[i].altura -= hijos;
    return hijos+1;
}

void asignarIndustria(){
    for(int i=1; i<=k; i++){
        esIndustria[vertice[i].ID]=true;
    }
}

void calcularFelicidad(int i, long long felicidadActual){
    if(felicidad[i])
        return;
    if(!esIndustria[i])felicidadActual++;
    felicidad[i]=felicidadActual;
    for(int u : v[i]){
        calcularFelicidad(u, felicidadActual);
    }
}

int main(){

    //leer
    cin>>n>>k;
    {
        int a, b;
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    //calcular altura
    vertice[1].altura = 0;
    vertice[1].ID = 1;
    calcularAltura(1, 1);
    /*cout<<"\n";
    for(int i=1; i<=n; i++){
        cout<<i<<" "<<vertice[i].altura<<"\n";
    }*/

    //asignar industria
    sort(vertice+1, vertice+n+1, greater<pair<int, int>>());
    asignarIndustria();

    /*cout<<"\n";
    for(int i=1; i<=n; i++){
        cout<<vertice[i].ID<<" "<<vertice[i].altura<<"\n";
    }*/
    /*cout<<"\n";
    for(int i=1; i<=n; i++){
        cout<<i<<" "<<esIndustria[i]<<"\n";
    }*/

    //calcular felicidad
    calcularFelicidad(1,0);
    long long felicidadTotal = 0;
    for(int i=1; i<=k; i++)
        felicidadTotal+=felicidad[vertice[i].ID];

    /*cout<<"\n";
    for(int i=1; i<=n; i++){
        cout<<i<<" "<<felicidad[i]<<"\n";
    }*/

    cout<<felicidadTotal<<"\n";
    return 0;
}
/*
6 2
1 2
2 3
4 3
4 6
5 1

9 4
1 2
2 3
4 3
4 6
1 5
6 7
6 8
6 9
*/
