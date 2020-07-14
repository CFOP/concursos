#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, n;
  cin>>n>>a>>b;
  int d(0);
  int c(0);
  while(n--){
    int p; cin>>p;
    if(p==1){
      if(a) a--;
      else if(b){
        b--;
        c++;
      }
      else if(c) c--;
      else d++;
    }
    else {
      if(b)b--;
      else d+=2;
    }
  }
  cout<<d<<"\n";
}
