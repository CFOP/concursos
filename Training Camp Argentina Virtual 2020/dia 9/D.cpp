#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int Z[MAX];
int times[MAX];
int sufx;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a;
  cin>>a;

  //Z[0]=1;
  for(int i=1; i<a.size(); i++){
    if(Z[i-1]>1 && Z[i-1]<a.size()-i && Z[ Z[i-1]-1 ]<Z[i-1]){
      Z[i] = Z[ Z[i-1]-1 ];
    }
    else {
      int j;
      for(j=0; j+i<a.size() && a[j]==a[j+i]; j++);
      Z[i]=j;
      if(i+j == a.size() && !sufx){
        //cout<<i<<" "<<j<<"\n";
        sufx = j+1;
      }
    }
    times[Z[i]]++;
    //cout<<Z[i]<<" ";
  }//cout<<"\n";

  times[0] = 0;
  int ans=0;
  int acum=0;
  //times[sufx]--;
  for(int i=sufx; i>0; i--){
    //cout<<times[i]<<" ";
    if(times[i]>=2){
      ans = i;
      break;
    }
    if(times[i]>0)acum++;
    if(acum>=2){
      ans = i;
      break;
    }
  }//cout<<"\n";
  //cout<<ans

  if(!ans){
    cout<<"Just a legend\n";
  }
  else {
    for(int i=0; i<ans; i++)
      cout<<a[i];
  }cout<<"\n";

  return 0;
}
