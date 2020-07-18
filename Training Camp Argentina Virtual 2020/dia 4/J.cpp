#include <bits/stdc++.h>
using namespace std;

int main(){
  int m = 99999999;
  int x1, x2, x3;
  cin>>x1>>x2>>x3;
  for(int i=0; i<=100; i++){
    m = min(m, abs(i-x1) + abs(i-x2) + abs(i-x3));
  }
  cout<<m<<"\n";
  return 0;
}
