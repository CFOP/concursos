#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> segment;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  while(n--){
    int l, r; cin>>l>>r;
    segment.push_back(make_pair(r,l));
  }
  sort(segment.begin(), segment.end(), less<pair<int, int>>());

  int l=-1;
  int total = 0;
  for(pair<int, int> p : segment){
    if(p.second>l){
      total++;
      l=p.first;
    }

  }

  cout<<total;
  return 0;
}




