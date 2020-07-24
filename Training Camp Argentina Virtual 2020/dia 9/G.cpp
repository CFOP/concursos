#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> segment; //end, begin

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  for(int i=0; i<n; i++){
    int a, b; cin>>a>>b;
    if(a>b)swap(a, b);
    segment.push_back( {b, a} );
  }

  sort(segment.begin(), segment.end());

  int ans = 1;
  vector <int> corte;
  corte.push_back(segment[0].first);

  for(pair<int, int> p : segment){
      if(*corte.rbegin()>=p.second) continue;
      ans++;
      corte.push_back(p.first);
  }

  cout<<ans<<"\n";
  for(int i:corte)
    cout<<i<<" ";
  cout<<"\n";

  return 0;
}
