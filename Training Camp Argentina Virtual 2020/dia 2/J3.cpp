#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k;
  cin>>n>>k;
  int s= 0;
  n--;
  for(int i=k-1; i>0; i--){
    if(n>=i){
      n-=i;
      s++;
    }
  }
  if(n)
    cout<<-1<<"\n";
  else
    cout<<s;
  return 0;
}
