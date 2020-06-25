#include <bits/stdc++.h>
#define MAX 3005
using namespace std;

string s, t;

int dp[MAX][MAX];
pair<int, int> last[MAX][MAX];
pair<int, int> mm;
int m;

void build(pair<int, int> p, int k){
    if(!k)
        return;

    //cout<<p.first<<" "<<p.second<<" "<<s[p.first-1]<<"\n";
    build(last[p.first][p.second], k-1);
    cout<<s[p.first];

}

int main(){
    cin>>s>>t;
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<t.size(); j++){
            if(s[i]==t[j]){ //son la misma letra
                if(dp[i][j]+1>dp[i+1][j+1]){ //es mejor opcion
                    dp[i+1][j+1]= dp[i][j]+1;
                    last[i+1][j+1].first = i;
                    last[i+1][j+1].second = j;
                }
                if(m<dp[i+1][j+1]){
                    mm=last[i+1][j+1];
                    m = dp[i+1][j+1];
                }
            }
            if(dp[i][j]>dp[i+1][j]){
                dp[i+1][j] = dp[i][j];
                last[i+1][j] = last[i][j];
            }
            if(m<dp[i+1][j]){
                mm = last[i+1][j];
                m = dp[i+1][j];
            }
            if(dp[i][j]>dp[i][j+1]){
                last[i][j+1]=last[i][j];
                dp[i][j+1]=dp[i][j];
            }
        }
    }
    /*for(int i=0; i<=s.size(); i++){
        for(int j=0; j<=t.size(); j++){
            cout<<last[i][j].first<<","<<last[i][j].second<<"|"<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<mm.first<<","<<mm.second<<"|"<<m<<"\n";*/
    int v = 0;
    build(mm, m);
    cout<<"\n";
    //cout<<m<<"\n";
    return 0;
}
/*
abracadabra
avadakedavra

aba
aka

abappp
apppba

bra
vada

na
ba

aaadara
*/
