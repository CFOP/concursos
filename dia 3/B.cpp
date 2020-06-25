#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int h[MAX];
int minimum[MAX];

int n, k;

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>h[i];
    memset(minimum, -1, sizeof(minimum));
    minimum[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k && i+j<n; j++){
                //cout<<"v";
                if(minimum[i+j]<0) minimum[i+j] = minimum[i]+abs(h[i]-h[i+j]);
                minimum[i+j] = min(minimum[i+j], minimum[i]+abs(h[i]-h[i+j]));
        }
    }
    cout<<minimum[n-1]<<"\n";
    return 0;
}
/*
4
10 30 40 20
0  20 30 30

4
10 50 10 10
*/

