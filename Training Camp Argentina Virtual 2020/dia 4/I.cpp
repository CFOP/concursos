//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t, d;
  string str;
  bool ans;

  cin >> t;

  while(t--){
    cin >> n;
    cin >> str;
    ans = true;
    for(int i = 0; i < n/2; i++){
      d = abs(str[i] - str[n-i-1]);
      if(d > 2 or d == 1){
        ans = false;
        break;
      }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
