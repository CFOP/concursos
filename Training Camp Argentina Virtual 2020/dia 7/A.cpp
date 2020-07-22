//Bernardo
#include <bits/stdc++.h>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long bottom, top;
  long long a, b;
  long long t, ans;

  cin >> t;

  while(t--){
    cin >> a >> b;
    bottom = sqrt(a); top = sqrt(b);
    ans = top - bottom;
    if(bottom * bottom == a) ans++;
    cout << ans << '\n';
  }

return 0;
}
