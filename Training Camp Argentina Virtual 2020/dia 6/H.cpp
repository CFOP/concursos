#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  string b = "hello";
  int p = 0;
  cin>>a;
  for(char c : a){
    if(c==b[p]){
      p++;
      if(p==b.size()){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  cout<<"NO\n";
  return 0;
}
