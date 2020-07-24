//Por Bernardo
#include <bits/stdc++.h>
using namespace std;
#define MAX 300001

int app[MAX];
long accum = 1;
int act_n[MAX];

int rr[MAX];
int notf[MAX];
long urr;

long max_t;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  int kind, num;

  cin >> n >> q;

  while(q--){
    cin >> kind >> num;

    if (kind == 1) {
      notf[num]++;
      app[accum] = num;
      act_n[accum] = notf[num];
      accum++;
      urr++;
    } else if(kind == 2) {
      urr -= (notf[num] - rr[num]);
      rr[num] = notf[num];
    } else if (num > max_t){
      for(int i = max_t + 1; i <= num; i++){
        if(rr[app[i]] < act_n[i]){
          rr[app[i]]++;
          urr--;
        }
      }
      max_t = num;
    }

    cout << urr << '\n';
  }


  return 0;
}

/*
fixprefixsuffix


*/
