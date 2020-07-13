#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
long long a[MAX];
long long c[MAX];
long long b[MAX];

long long bruta(){
    sort(b, b+n);
    for(int i=n-1; i>0; i--){
        //cout<<b[i];
        for(int j=i-1; j>=0; j--){
            int a1, a2;
            a1 = b[i]&b[j];
            a2 = b[i]|b[j];
            b[i]=a2;
            b[j]=a1;
        }
    }

    long long s = 0;
    for(int i=0; i<n; i++){
        s+=(long long)b[i]*(long long)b[i];
    }

    for(int i=0; i<n; i++)cout<<b[i]<<" ";
    cout<<"\n";
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    long long oR=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        c[i]=b[i]=a[i];
    }
    sort(a, a+n);

    long long anD=a[n-1];
    for(int i=0; i<n-1; i++)oR|=a[i];
    for(int i=0; i<n; i++)anD&=a[i];

    for(int i=0; i<n; i++){
        c[i]&=anD;
        anD|=a[i];
    }
    for(int i=n-1; i>=0; i--){
        c[i]|=oR;
        oR&=a[i];
    }

    for(int i=0; i<n; i++)cout<<c[i]<<" ";
    cout<<"\n";
    long long s = 0;
    for(int i=0; i<n; i++){
        s+=(long long)c[i]*(long long)c[i];
    }
    cout<<s<<"\n";
    cout<<bruta()<<"\n";
    return 0;
}

/*
10
2 4 5 6 8 4 2 1 10 11

3
1 10 11
*/
