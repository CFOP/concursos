#include <bits/stdc++.h>

using namespace std;
#define Lim 200005

typedef long long ll;
int n;

struct ST

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>Arr[i];
    buildTree(0, 0, n-1);
    for(int i=0; i<n*4; i++)
        cout<<Tree[i]<<" ";
    cout<<"\n";
    cout<<queryTree(0, 1, 3, 0, 4*n)<<"\n";
    return 0;
    long long ans = 0;
    for(int i=1; i<=n; i++){
        ans = 0;
        for(int j=0; j+i-1<n; j++)
            ans = max(ans, queryTree(0, j, j+i-1, 0, n-1));
        cout<<ans;
        if(i<n)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

/*
5
1 2 3 4 5
*/
