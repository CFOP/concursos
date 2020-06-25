#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int h[MAX];
int minimum[MAX];

int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>h[i];
    memset(minimum, -1, sizeof(minimum));
    minimum[0]=0;
    for(int i=0; i<n-1; i++){
        //if(i<n-1)cout<<minimum[i]<<" "<<minimum[i+1]<<" "<<minimum[i+2]<<"\n";
        if(minimum[i+1]<0) minimum[i+1] = minimum[i]+abs(h[i]-h[i+1]);
        minimum[i+1] = min(minimum[i+1], minimum[i]+abs(h[i]-h[i+1]));
        if(i<n-2) {
                if(minimum[i+2]<0) minimum[i+2] = minimum[i]+abs(h[i]-h[i+2]);
                minimum[i+2] = min(minimum[i+2], minimum[i]+abs(h[i]-h[i+2]));
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
