#include <bits/stdc++.h>
using namespace std;

#define MAX 200000

int a[MAX], b[MAX];

int main(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  for(int i=0; i<n; i++)
    cin>>b[i];

  int j=0;
  int i=0;
  if(b[i]==0)i++;
  for(j=0; j<n && b[i]!=a[j]; j++);
  //cout<<j;
  for(; i<n; i++, j++){
    j = j%n;
    //cout<<a[j]<<" "<<b[i]<<"\n";
    if(!a[j] && !b[i])
      continue;
    if(!a[j]){
      i--;
      continue;
    }
    if(!b[i]){
      j--;
      continue;
    }
    if(a[j]!=b[i]){
      cout<<"NO\n";
      return 0;
    }
  }
  cout<<"YES\n";
  return 0;
}

/*
4
1 2 3 0
0 2 3 1

1 2 0 3
*/
