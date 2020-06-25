#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

struct Item{
    int w;
    int v;
}item[105];

int N, W;
long long dp[105][MAX];
long long m;

int main(){
    cin>>N>>W;
    for(int i=0; i<N; i++)
        cin>>item[i].w>>item[i].v;
    for(int i=0; i<N; i++){
        for(int j=0; j<=W; j++){
            if(item[i].w+j<=W){
                dp[i+1][item[i].w+j] = max(dp[i+1][item[i].w+j], dp[i][j]+item[i].v);
                m = max(dp[i+1][item[i].w+j], m);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            m = max(dp[i+1][j], m);
        }
    }
    cout<<m<<"\n";
    return 0;
}
