#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
const int oo = 1e9;

int n;

int maximo=0;

struct st{ /// informacion de cada nodo
  st *left, *right;
  int l, r, m;
  int Min, Max;
  st(int l, int r) : l(l), r(r), Min(oo), Max(0) {
    if(l != r) {
      m = (l+r)/2;
      left = new st(l, m);
      right = new st(m+1, r);
    }
  }
  void update(int pos, int v) {
    if(l == r) {
      Min = Max = v;
    } else {
      if(pos <= m) left->update(pos, v);
      else right->update(pos, v);
      Min = min(left->Min, right->Min);
      Max = max(left->Max, right->Max);
    }
  }
  int get(int s) {
    if(r - l <= s) return Min;
    if(Max < maximo) return Max;
    if(r==l) return Max;
    //cout<<s<<" "<<l<<" "<<r<<" "<<Min<<"\n";
    //if(a > r || b < l) return oo;
    //if(l - r + 1 < s) return sum;
    int total = max(left->get(s), right->get(s));
    maximo = max(total, maximo);
    return total;
    //return min(left->get(a, b), right->get(a, b));
  }
};

int main(){
  cin>>n;
  st tree(0, n-1);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    tree.update(i, x);
  }
  int ans;
  for(int i=0; i<n; i++){
        maximo = 0;
        cout<<tree.get(i);
        if(i<n)cout<<" ";
    }
    cout<<"\n";
}
