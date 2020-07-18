//por bernardo
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int n;
  int div = 1;

  cin >> n;

  for(int i = 2; i <= sqrt(n); i++)
    if(n % i == 0)
      div = i;

  cout << 2 * div + 2 * (n / div) << '\n';

}
