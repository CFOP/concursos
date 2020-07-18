//por bernardo
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000001;

unordered_map <int, int> M;

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int a, b, x, y;
  long long sum = 0;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a >> x;
    M[a] = x;
  }

  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> b >> y;
    if(M.find(b) == M.end()) M[b] = 0;
    M[b] = max(M[b], y);
  }

  for(auto x : M)
    sum += x.second;

  cout << sum <<'\n';

  return 0;
}

