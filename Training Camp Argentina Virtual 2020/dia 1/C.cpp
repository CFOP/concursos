#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> b;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin>>m>>n;
  long long sumA(0), sumB(0);

  for(int i=0; i<m; i++){
    int row; cin>>row;
    a.push_back(row);
    sumA += row;
  }

  for(int i=0; i<n; i++){
    int row; cin>>row;
    b.push_back(row);
    sumB += row;
  }

  long long minA(0), minB(0);
  for(int i=0; i<m; i++){
    if(a[i]<sumB)
      minA+=a[i];
    else{
      minA+=sumB;
    }
  }
  long long maxElement = *max_element(a.begin(), a.end());
  if(maxElement<sumB){
    minA-=maxElement;
    minA+=sumB;
  }

  for(int i=0; i<n; i++){
    if(b[i]<sumA)
      minB+=b[i];
    else{
      minB+=sumA;
    }
  }
  maxElement = *max_element(b.begin(), b.end());
  if(maxElement<sumA){
    minB-=maxElement;
    minB+=sumA;
  }

  cout<<min(minA, minB)<<"\n";

}
