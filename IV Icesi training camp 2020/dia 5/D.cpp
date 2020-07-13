#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int p[MAX];
int query[MAX];
int answer[MAX];
bool toCut[MAX];
int componentes;

int n, m, q;

vector<pair<int, int>> th;

int Find(int n){
    if(p[n]==n)
        return n;
    return p[n] = Find(p[n]);
}
void Union(int a, int b){
    if(Find(a)!=Find(b)) componentes--;
    p[Find(a)] = p[Find(b)];
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        p[i]=i;
    componentes=n;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        th.push_back(make_pair(a, b));
    }
    cin>>q;
    for(int i=1; i<=q; i++){
        cin>>query[i];
        toCut[query[i]-1]=true;
    }

    /*for(int i=1; i<=n; i++)
        cout<<p[i]<<" ";
    cout<<"#"<< componentes <<"\n";*/

    for(int i=0; i<m; i++){
        if(!toCut[i]){
            Union(th[i].first, th[i].second);
        }
    }

    /*for(int i=1; i<=n; i++)
        cout<<p[i]<<" ";
    cout<<"#"<< componentes <<"\n";*/

    for(int i=q; i>0; i--){
        answer[i]=componentes;
        Union(th[query[i]-1].first, th[query[i]-1].second);

        /*for(int i=1; i<=n; i++)
            cout<<p[i]<<" ";
        cout<<"#"<< componentes <<"\n";*/

    }

    for(int i=1; i<q; i++){
        cout<<answer[i]<<" ";
    }
    cout<<answer[q]<<"\n";

    return 0;
}

