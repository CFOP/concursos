#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define MAXT 25

    //[ t][ x ]
int dp[MAXT][MAX];
int M[MAXT][MAX];
int x;
vector <int> step;
int steps;

void back(int i, int j){
  if(i==0){
    cout<<steps<<"\n";
    return;
  }
  steps+=2;
  back(i-1, dp[i][j]);
  cout<<M[i][j]<<" "<<j<<"\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<MAXT; i++)
    for(int j=0; j<MAX; j++) dp[i][j]=-1;

  cin>>x;

  dp[0][x] = 0;
  for(int i=0; i<MAXT-5; i++){
      for(int j=0; j<MAX-1; j++){
        if(dp[i][j]==-1) continue; //no se puede

        //if((i+1)%2){ //A
          for(int m = 0; m<=21 /*&& ((1<<m) -1)<=i*/; m++){
            if((j^( (1<<m) -1 ))+1 < MAX){
              dp[i+1][(j^( (1<<m) -1 ))+1] = j; //A y B
              M[i+1][(j^( (1<<m) -1 ))+1] = m; //
              /*if((j^( (1<<m) -1 ))+1 < MAX) {
                  dp[i+1][j^( (1<<m) -1 )+1] = j;
                  M[i+1][j^( (1<<m) -1 )+1] = m;
              }*/
            }
          }
        //}
        //else { //B
          //dp[i+1][j+1]=j;
        //}

      }
  }

  for(int i=0; i<MAXT-1; i++){
    for(int j=0; j<20 && ((1<<j) -1)<=i ; j++){
      if(dp[i][(1<<j) -1 ]!=-1){
        //cout<<(1<<j) -1<<"\n";
        //cout<<(1<<j) -1<<"\n";
        //cout<<i<<"\n";
        steps--;
        back(i, (1<<j) -1);
        return 0;
      }
      /*else if(dp[i][(1<<j)]!=-1){
        //cout<<(1<<j) -1<<"\n";
        //cout<<i<<"\n";
        steps++;
        back(i, (1<<j) -1);
        return 0;
      }*/
    }
  }

  return 0;
}

// Runtime error: exit code is -1073741819

/*
// 39
5
5 56
3 62
6 0
*/
