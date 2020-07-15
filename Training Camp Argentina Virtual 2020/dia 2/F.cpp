//por Bernardo
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2002;
const long long MOD = 1000000007;


//              n    k
long sequences[MAX][MAX];
unordered_set<int> divisor[MAX];

long my_sum(long a, long b){
  long long s = a + b;
  if (s > MOD)
    return s - MOD;
  else if(s < 0)
    return s + MOD;
  else
    return s;
}

int main(){
  int n, k, top, sum;
  cin >> n >> k;

  for(int i = 2; i <= n; i++){
    top = ceil(sqrt(i));
    for(int j = 1; j < top; j++)
      if(i % j == 0){
        divisor[i].insert(j);
        divisor[i].insert(i/j);
      }
    if(i % top == 0) divisor[i].insert(top);
  }

  for(int i = 1; i <= n; i++)
    sequences[i][1] = i;

  for(int j = 2; j <= k; j++){
    sum = 0;
    sequences[1][j] = 1;
    for(int i = 2; i <= n; i++){
      for(int x : divisor[i]){
        sequences[i][j] = my_sum(sequences[i][j], - sequences[x-1][j-1]);
        sequences[i][j] = my_sum(sequences[i][j], sequences[x][j-1]);
      }
      sequences[i][j] = my_sum(sequences[i][j], sequences[i-1][j]);
    }
  }

  cout << sequences[n][k] << '\n';

}
