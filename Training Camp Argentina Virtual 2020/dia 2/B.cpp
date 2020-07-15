#include <iostream>
using namespace std;

bool isPrime(int n){
  if(n==1)
    return false;
  for(int i=2; i*i<=n; i++)
    if(!(n%i)) return false;
  return true;
}

int main() {
  int n;
  cin>>n;
  //cout<<isPrime(5);
  for(int i=1; i<=1000; i++){
    if(!isPrime(n*i+1)){
      cout<<i<<"\n";
      return 0;
    }
  }
  return 0;
}
