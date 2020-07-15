//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int const MAX = 101;


long double dp[MAX][MAX][MAX][3];

int main(){
  int r, s, p;
  long double comb;
  long double w;

  cin >> r >> s >> p;

  for(int i = 1; i <= r; i++)
    for(int j = 0; j <= s; j++){
      dp[i][j][0][0] = 1;
      dp[i][j][0][1] = 0;
      dp[i][j][0][2] = 0;
    }

  for(int i = 1; i <= s; i++)
    for(int j = 0; j <= p; j++){
      dp[0][i][j][0] = 0;
      dp[0][i][j][1] = 1;
      dp[0][i][j][2] = 0;
    }

  for(int i = 1; i <= p; i++)
    for(int j = 0; j <= r; j++){
      dp[j][0][i][0] = 0;
      dp[j][0][i][1] = 0;
      dp[j][0][i][2] = 1;
    }

  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= s; j++)
      for(int k = 1; k <= p; k++){
        comb = i * j + j * k + k * i;
        dp[i][j][k][0] = 0;
        dp[i][j][k][1] = 0;
        dp[i][j][k][2] = 0;

        w = ((k * i) / comb);
        for(int m = 0; m < 3; m++)
          dp[i][j][k][m] += dp[i-1][j][k][m] * w;

        w = ((i * j) / comb);
        for(int m = 0; m < 3; m++)
          dp[i][j][k][m] += dp[i][j-1][k][m] * w;

        w = ((j * k) / comb);
        for(int m = 0; m < 3; m++)
          dp[i][j][k][m] += dp[i][j][k-1][m] * w;
      }

  cout.precision(12);
  cout << fixed;
  cout << dp[r][s][p][0] << ' ' << dp[r][s][p][1] << ' ' << dp[r][s][p][2] << '\n';

}
