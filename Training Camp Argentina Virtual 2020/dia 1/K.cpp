#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin>>t;

  while(t--){
    string a; cin>>a;
    cout<<a[0];
    for(int i = 1; i<a.size();i+=2)
      cout<<a[i];
    cout<<"\n";
  }

}
