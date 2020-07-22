//Bernardo
#include <bits/stdc++.h>
using namespace std;

int sum(long long n){
  int ans = 0;
  while(n > 0){
    ans += n % 10;
    n/= 10;
  }
  if (ans >= 10) ans = sum(ans);
  return ans;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long a, b; cin>>a>>b;

  long long v = 1;
  a = sum(a);

  for(int i = 0; i < b; i++){
    v *= a;
    v = sum(v);
  }

  cout << v << '\n';

  return 0;
}
