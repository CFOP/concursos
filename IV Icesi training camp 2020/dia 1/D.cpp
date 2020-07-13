#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    unsigned long long a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b<a){
            swap(a, b);
        }
        //cout<<a<<" "<<b<<" ";
        int i;
        for(i=0; a<b; i++){
            if(a<b){
                for(int j=0; j<3 && a<b; j++){
                   a*=2;
                   //cout<<a<<" ";
                }
            }
        }
        if(a==b)
            cout<<i<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
