//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t;
  cin >> t;
  while(t--){
    cin>>n;

    if(n < 3)
      cout << 0 << '\n';
    else
      cout << n - 2 << '\n';
  }
}
