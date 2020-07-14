//Por Bernardo
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin>>t;
  int n, input;
  bool even, odd;
  while(t--){
    cin >> n;
    even = odd = false;
    for(int i = 0; i < n; i++){
      cin >> input;
      odd = odd or input % 2;
      even = even or not (input % 2);
    }
    if (not odd)
      cout << "NO\n";
    else if (n % 2)
      cout << "YES\n";
    else if (not even)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

}
