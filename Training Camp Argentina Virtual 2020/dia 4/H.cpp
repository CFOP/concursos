#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int happy(string name, string t){
  int j=0;
  for(int i=0; i<t.size(); i++){
    if(t[i]==name[j])
      j++;
    if(j==name.size())
      return i;
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin>>s;
  cin>>t;
  if(s.size()>t.size()){
    cout<<0<<"\n";
    return 0;
  }

  int a = happy(s, t);
  reverse(t.begin(), t.end());
  reverse(s.begin(), s.end());
  int b = t.size()- happy(s, t) - 1;
  //cout<<a<<" "<<b<<"\n";
  int total = b-a;
  if(total<=0 || a==-1 || b==-1){
    cout<<0;
    return 0;
  }

  cout<<total<<"\n";
  return 0;
}



