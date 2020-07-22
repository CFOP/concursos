//Berdnardo
#include <bits/stdc++.h>
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

      ios_base::sync_with_stdio(false);
      cin.tie(0);

      init_pow();

      string str; cin >> str;

      long long ans = 0;
      long long mul, cont, contb = 0;

      int j = str.size() - 1;

      while(j >= 0){
        while(str[j] == 'b' and j >= 0){
          contb++;
          j--;
        }
        cont = 0;
        while(str[j] == 'a' and j >= 0){
          cont++;
          j--;
        }
        if(cont){
          ans += (contb * (pow_mod[cont] - 1)) % MOD;
          ans -= MOD * (ans >= MOD);
          contb = (contb * pow_mod[cont]) % MOD;
        }
      }

      cout << ans << '\n';

    return 0;
    }
