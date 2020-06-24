#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    int a, b;
    map<pair<int, int>, int> s;
    for(cin>>n; n; cin>>n){
        s.clear();
        for(int i=0; i<n; i++){
            cin>>a>>b;
            pair<int, int> in(b,a);
            if(s.find(in)==s.end()){//no esta
                if(s.find(make_pair(a, b))==s.end())
                    s[make_pair(a, b)]=0;
                s[make_pair(a, b)]++;
            }
            else {
                s[make_pair(b, a)]--;
                if(s[make_pair(b, a)]==0)
                    s.erase(make_pair(b, a));
            }
        }
        if(s.empty()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
