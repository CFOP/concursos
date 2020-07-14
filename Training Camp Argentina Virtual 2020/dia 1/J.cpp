#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long a, b, d;
  cin>>n>>d>>a>>b;
  vector <pair<long long, int>> client; //costo, ID
  for(int i=0; i<n; i++){
    long long x, y;
    cin>>x>>y;
    client.push_back(make_pair(x*a+y*b, i+1));
  }
  sort(client.begin(), client.end(), less<pair<long long, int>>());
  int c;
  for(c=0; c<n && client[c].first<=d; c++){
    d-=client[c].first;
  }
  cout<<c<<"\n";
  for(int i=0; i<c-1; i++)
    cout<<client[i].second<<" ";
  if(c>0)
    cout<<client[c-1].second<<"\n";
}
