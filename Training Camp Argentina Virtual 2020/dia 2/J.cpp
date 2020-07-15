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
  while(true){
      long long n, k;
      long long N, s2=0;
      s=0;
      //cin>>n>>k;
      n= rand() % 50 + 1;
      N=n;
      k = rand() % 20 + 2;
      cout<<n<<" "<<k<<" ";

      if(n<=k){
        n=0;
        s=1;
      }

      n--;
      for(int i=k-1; i>0;i--){
        n-=next(i, n, 0, i);
        next2(i, n, 0, i);
        i++;
        //next2(i, n, 0, i);
      }

      N--;
      for(int i=k-1; i>0; i--){
        if(N>=i){
          N-=i;
          s2++;
        }
      }
      cout<<s<<" "<<s2<<"\n";
      if(s!=s2 && !n && !N){
        int p; cin>>p;
      }
      if((bool)n!=(bool)N){
        int p; cin>>p;
      }
  }
  /*
    if(n)
    cout<<-1<<"\n";
  else
    cout<<s;

  */
  return 0;
}

