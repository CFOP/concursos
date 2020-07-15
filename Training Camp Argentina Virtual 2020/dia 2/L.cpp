//por Bernardo
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 2005

    //[ i ][ j ]
int dp[MAX][MAX]; // cuantos buenos puedo obtener si n=i y k=j

int main(){
  int n;
  cin >> n;
  if(n%2)
    cout << "black\n";
  else
    cout << "white\n1 2\n";
  return 0;
}
