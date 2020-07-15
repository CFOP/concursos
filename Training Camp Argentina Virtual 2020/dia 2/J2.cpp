#include <bits/stdc++.h>
using namespace std;

int s= 0;

long long sum(long long n, long long m){
  n--;
  return (m*(m+1))/2-(n*(n+1))/2;
}

long long next(int &i, long long n, int l, int r){ //(]
  //cout<<l<<" "<<r<<"\n";
  if(l+1>=r){
    int p = i;
    i=r;
    s+=p-r+1;
    //cout<<"#"<<r<<" "<<i<<" "<<sum(r, i)<<"\n";
    return sum(r, p);
  }
  int m = (l+r)/2;
  if(sum(m, i)<=n)//1
    return next(i, n, l, m);
  return next(i, n, m, r);
}

void next2(int &i, long long n, int l, int r){ //[)
  if(l+1>=r){
    i=l;
    return;
  }
  int m = (l+r)/2;
  if(m>n)
    next2(i, n, l, m);
  else
    next2(i, n, m, r);
}

int main(){
  //cout<<sum(2, 3);
  long long n, k;
  cin>>n>>k;
  if(n==1){
    cout<<0<<"\n";
    return 0;
  }
  n--;
  if(n<k){
    cout<<1<<"\n";
    return 0;
  }
  for(int i=k-1; i>0; i--){
    n-=next(i, n, 0, i);
    next2(i, n, 0, i);
    i++;
    //next2(i, n, 0, i);
  }
  if(n)
    cout<<-1<<"\n";
  else
    cout<<s;
  return 0;
}

