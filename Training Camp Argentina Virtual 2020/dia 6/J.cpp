#include <bits/stdc++.h>
using namespace std;

#define MAX 300

string a, b;

int minDis[MAX][MAX];
char to[MAX][MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b;

  for(int i=0; i<MAX; i++)
    for(int j=0; j<MAX; j++)
      minDis[i][j]=-1;

  for(char i='a'; i<='z'; i++){
    minDis[i][i]  = 0;
    to[i][i] = i;
  }

  int n; cin>>n;
  while(n--){
    char a, b;
    int w;
    cin>>a>>b>>w;

    if(minDis[a][b]==-1){
      minDis[a][b]=w;
    }

    minDis[a][b] = min(minDis[a][b], w);
    to[a][b] = b;
  }

  for(char k='a'; k<='z'; k++)
    for(char i='a'; i<='z'; i++)
      for(char j='a'; j<='z'; j++){
        if(minDis[i][k]<0) continue;
        char a = to[i][k];
        if(minDis[k][j]>=0){
          char b = to[k][j];
          //if(a!=b)cout<<a<<b<<"\n";
          if(minDis[a][b]>=0 && minDis[i][a]>=0 && minDis[b][j]>=0){
            if(minDis[i][j]<0 || minDis[i][a]+minDis[b][j] + minDis[a][b] < minDis[i][j] ) {
              minDis[i][j] = minDis[i][a] + minDis[b][j] + minDis[a][b];
              to[i][j] = to[a][b];
            }
          }
        }
        if(minDis[j][i]>=0 && (minDis[j][i] < minDis[i][j] || minDis[i][j] < 0 )){
          minDis[i][j] = minDis[j][i];
          to[i][j] = to[j][i];
        }
        if(minDis[j][i]<0 || (minDis[i][j] < minDis[j][i] && minDis[j][i] >= 0 )){
            minDis[j][i] = minDis[i][j];
            to[j][i] = to[i][j];
        }

      }

  if(a.size()!=b.size()){
    cout<<-1<<"\n";
    return 0;
  }

  long long total = 0;
  for(int i=0; i<a.size(); i++){
      if(minDis[a[i]][b[i]]<0){
        cout<<-1<<"\n";
        return 0;
      }
      //cout<<a[i]<<"#\n";
      total += minDis[a[i]][b[i]];
      a[i] = to[a[i]][b[i]];
  }

  cout<<total<<"\n"<<a<<"\n";

  return 0;
}



/*
a
e
6
a b 1
b f 1
d f 1
e d 1
c d 1
c b 1

a
e
4
a b 1
e d 1
c d 1
c b 1

y
x
1
x y 1

y
x
1
y x 1

y
x
1
x y 13

*/
