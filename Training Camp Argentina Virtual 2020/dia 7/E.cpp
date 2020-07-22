#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, m;
  int mid, nines, front, posfix = 0;

  cin >> m;
  n = m - 1;

  if(m == 1){
    cout << 1 << '\n';
  } else {
    if(n > 8){
      mid = 8;
      nines = (n - 8) / 9;
      front = (n - 8) % 9;
    } else {
      mid = n % 9;
      nines = 0;
      front = 0;
    }

    for(long long i = 1; i < m; i++){
      if((i * 9) % m == 1){
        posfix = i;
        break;
      }
    }

    if(posfix){
      if(front) cout << front;
      while(nines--) cout << 9;
      cout << mid;
      while(posfix--) cout << 9;
      cout << '\n';
    } else {
      cout << "-1\n";
    }

  }

  return 0;
}
