#include <bits/stdc++.h>
using namespace std;

int v[105];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>v[i];
    int fO=v[0], sO;
    for(int i=0; i<n; i++){
        if(v[i]<fO)
            fO=v[i];
    }
    sO=fO;
    for(int i=0; i<n; i++){
        if(sO==fO)
            sO=v[i];
        if(v[i]!=fO && v[i]<sO)
            sO=v[i];
    }
    if(fO==sO)
        cout<<"NO\n";
    else
        cout<<sO<<"\n";
    return 0;
}
