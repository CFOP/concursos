//por Bernardo y Yoguel
#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1000000005;

int n, x, y, c;
//long long gauss(MAX];

long long gauss(long long k){
  /*gauss(0] = 0;
  for(int i = 1; i < MAX; i++)
    gauss(i] = gauss(i - 1] + i;*/
  return (k * (k + 1)) / 2;
}

long long extra(long long n){
  return (long long) 2 * gauss(n - 1) + n;
}


long long on_cell(long long d){
  long long ans = 4 * gauss(d) + 1;

  if(n - x < d)
    ans -= extra(d - n + x);
  if(x - 1 < d)
    ans -= extra(d - x + 1);
  if(n - y < d)
    ans -= extra(d - n + y);
  if(y - 1 < d)
    ans -= extra(d - y + 1);

  if(2 * n - x - y + 1 < d)
    ans += gauss(d - (2 * n - x - y + 1));
  if(n - x + y < d)
    ans += gauss(d - (n - x + y));
  if(x + y - 1 < d)
    ans += gauss(d - (x + y - 1));
  if(n - y + x < d)
    ans += gauss(d - (n - y + x));

  return ans;

}

int f(int left, int right){ // (left, right]
  if(left+1>=right)
    return right;
  //cout<<left<<" "<<right<< "\n";
  int middle = (left+right)/2;
  if(on_cell(middle) >= c){ //1
    return f(left, middle);
  }
  else { //0
    return f(middle, right);
  }
}


//
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x >> y >> c;

  if(c<=1){
    cout<<0<<"\n";
  }
  else {
    cout<<f(0, MAX)<<"\n";
  }
  //cout<<on_cell(2);

}

