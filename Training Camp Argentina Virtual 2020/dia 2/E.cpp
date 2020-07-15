//por Bernardo
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int m, n, act, sum = 0;
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    cin >> act;
    sum += act;
  }
  if(m == 0)
    cout << 0 << '\n';
  else
    cout << ceil(abs(sum)/(m+0.0L)) <<'\n';
  return 0;
}
