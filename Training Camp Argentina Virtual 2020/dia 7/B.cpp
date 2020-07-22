//Por Bernardo
#include <bits/stdc++.h>
using namespace std;


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;

  vector <int> a(n);
  vector <int> b(n);

  for(int i=0; i<n; i++)
      cin>>a.at(i);

  sort(a.begin(), a.end());

  int j, i;
  for(i=0, j=0; i<a.size(); i+=2, j++){
    b.at(j) = a.at(i);
  }
  i-=2;
  if(i<a.size()-1)
    i++;
  else i--;
  for(; i>=0; i-=2, j++){
    b.at(j) = a.at(i);
  }

  for(int k : b){
    cout<<k<<" ";
  }
  cout<<"\n";

  return 0;
}
