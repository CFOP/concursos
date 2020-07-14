//Por Bernardo
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t, a, b;
  cin >> t;
  while(t--){
    cin >> a >> b;
    if (a == b)
      cout << "0\n";
    else if (a < b != (a + b) % 2)
      cout << "2\n";
    else
      cout << "1\n";
  }
}
