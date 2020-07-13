#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, m;
vector <int> v[MAX];
int s[MAX];

int main(){
    cin>>n>>m;
    {
        int a, b;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    queue<int> next;
    s[1] = 1;
    for(int u : v[1]){
        if(s[u])continue;
        //cout<<u<<"\n";
        s[u]=1;
        next.push(u);
    }

    while(!next.empty()){
        int u = next.front();
        next.pop();
        for(int i:v[u]){
            if(s[i]) continue;
            s[i] = s[u]+1;
            next.push(i);
        }
    }

    /*cout<<"\n";
    for(int i=1; i<=n; i++)
        cout<<i<<"\t"<<s[i]<<"\n";*/

    cout<<s[n]-1<<"\n";

    return 0;
}
/*
4 3
1 2
2 3
3 4
*/
