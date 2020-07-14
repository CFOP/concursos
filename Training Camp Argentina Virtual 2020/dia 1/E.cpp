//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, input, total, mid, pos;
  cin >> n;
  cin >> arr[0];
  for(int i = 1; i < n; i++){
    cin >> input;
    arr[i] = arr[i - 1] + input;
  }
  total = arr[n-1];
  mid = total / 2;

  pos = upper_bound(arr, arr+n, mid) - arr;

  if (n == 1)
    cout << "1 0\n";
  else if (arr[pos - 1] > total - arr[pos])
    cout << pos << ' ' << n - pos << '\n';
  else
    cout << pos + 1 << ' ' << n - pos - 1 << '\n';

}
