//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p, i, j;
  string str;
  bool possible = false;
  cin >> n >> p;
  cin >> str;
  i = 0;
  j = p;
  while(j < n){
    if(str[i] == str [j]){
      if(str[i] == '.'){
        possible = true;
        str[i] = '0';
        str[j] = '1';
        break;
      }
    } else {
      if(str[i] == '.')
        str[i] = to_string(not bool(str[j] - '0'))[0];
      if(str[j] == '.')
        str[j] = to_string(not bool(str[i] - '0'))[0];
      possible = true;
      break;
    }

    i++;
    j++;
  }

  if(possible){
    for(char c : str)
      if(c == '.') cout << '0';
      else cout << c;
    cout << '\n';
  } else {
    cout << "No\n";
  }

  return 0;
}
