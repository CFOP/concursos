//Por Bernardo
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

long long V[MAX];
long long T[MAX];
long long A[MAX];
long long E[MAX];

struct st{
  st *left, *right;
  int times, l, r, m, lazy;
  st(int l, int r) : l(l), r(r), times(0), lazy(0) {
    if(l != r) {
      m = (l+r)/2;
      left = new st(l, m);
      right = new st(m+1, r);
    }
  }
  void propagate() {
    if(lazy != 0) {
      times += (r-l+1) * lazy;
      if(l != r) {
        left->lazy += lazy;
        right->lazy += lazy;
      }
      lazy = 0;
    }
  }
  void update(int a, int b) {
    propagate();
    if(a > r || b < l) return;
    if(a <= l && r <= b) {
      lazy = 1;
      propagate();
      return;
    }
    left->update(a, b);
    right->update(a, b);
    times = left->times + right->times;
  }

  int get(int a, int b) {
    propagate();
    if(a > r || b < l) return 0;
    if(a <= l && r <= b) return times;
    return left->get(a, b) + right->get(a, b);
  }

  int get(int a){
    return get(a, a);
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, day;

  cin >> n;

  st days(1, n);

  for(int i = 1; i <= n; i++)
    cin >> V[i];

  A[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> T[i];
    A[i] = A[i - 1] + T[i];
  }

  int pos;
  for(int i = 1; i <= n; i++){
    day = upper_bound(A, A + n + 1, V[i] + A[i -1]) - A;
    E[day] += V[i] - (A[day-1] - A[i - 1])
    * bool( V[i] - (A[day-1] - A[i - 1]) > 0);
    days.update(i, day - 1);
  }
  for(int i = 1; i < n; i++)
    cout << T[i] * days.get(i) + E[i] << ' ';
   cout << T[n] * days.get(n) + E[n] << '\n';

  return 0;
}
