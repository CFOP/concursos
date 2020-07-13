#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
int d[3][MAX];
long long dp[3][MAX];
long long m;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++)
            cin>>d[j][i];
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++){
                if(k!=j)dp[j][i] = max(dp[k][i-1]+d[j][i], dp[j][i]);
                m = max(dp[j][i], m);
            }
    }
    cout<<m<<"\n";
    return 0;
}
/*
3
10 40 70
20 50 80
30 60 90
*/
