#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, s;
  cin>>a>>b>>s;
  long long minDis = abs(a)+abs(b);
  long long dif = s - minDis;
  if(dif<0) dif = 1;
  if(dif%2)
    cout<<"No\n";
  else
    cout<<"Yes\n";
  return 0;
}
