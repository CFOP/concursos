#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

struct Item{
    long long w;
    int v;
}item[105];

long long N, W;
long long dp[105][MAX];
int m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>W;
    for(int i=0; i<N; i++){
        cin>>item[i].w>>item[i].v;
        if(item[i].w<=W){
                dp[i+1][item[i].v] = item[i].w;
                m = max(m, item[i].v);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<=MAX; j++){
            if(!dp[i][j])continue;

            m = max(m, j);
            if(!dp[i+1][j]) dp[i+1][j]=dp[i][j];
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            if(dp[i][j]+item[i].w>W)continue;

            m = max(m, j+item[i].v);
            if(!dp[i+1][j+item[i].v]){
                dp[i+1][j+item[i].v]=item[i].w+dp[i][j];
                continue;
            }
            dp[i+1][j+item[i].v] = min(dp[i+1][j+item[i].v], dp[i][j]+item[i].w);

        }
    }
    /*for(int i=0; i<=N; i++){
        for(int j=0; j<=30; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<m<<"\n";
    return 0;
}

