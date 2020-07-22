//Bernardo
include <bits/stdc++.h>
using namespace std;


const int MOD = 1000000007;
const int MAX = 1000001;

long long pow_mod[MAX];

void init_pow(){
  pow_mod[0] = 1;
  for(int i = 1; i < MAX; i++){
    pow_mod[i] = pow_mod[i-1] * 2;
    pow_mod[i] -= MOD * (pow_mod[i] >= MOD);
  }
}

int main() {

  long long n, sq, p, sqp;

  cin >> n;

  sq = sqrt(n);

  if(n == 1){
    cout << "NO\n";
  } else if(sq*sq == n){
    cout << "YES\n";
  } else{
    for(long long i = sq; i > 0; i--){
      if(n % (i * i) == 0){
        p = n / (i * i);
        sqp = sqrt(p);
        int j = 2;
        for(j = 2; j <= sqp; j++){
          if(p % j == 0){
            cout << "NO\n";
            break;
          }
        }
        if(j > sqp) cout << "YES\n";
        break;
      }
    }
  }
  return 0;
}
