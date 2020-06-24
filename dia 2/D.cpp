#include <bits/stdc++.h>

using namespace std;

int n, c;
long long stall[100005];

bool itsPosible(long long x){
    //cout<<x<<" ";
    int i=1;
    int j;
    long long d = 0;
    for(j=1; j<n && i<c; j++){
        d+=stall[j]-stall[j-1];
        if(d>=x){
            i++;
            d=0;
        }
    }
    //cout<<i<<" "<<c<<"# ";
    return i>=c;
}

long long search(long long first, long long last){
    if(first>last)
        return last;
    long long middle = (first+last)/2;
    //cout<<middle<<" "<<" "<<itsPosible(middle)<<"\n";
    if(itsPosible(middle)){
        return search(middle+1, last);
    }
    return search(first, middle-1);
}
/*
1 1 0
1 0
1 1
1 1 1 1 1 0 0 0 0 0 0
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        //cout<<c<<"#\n";
        for(int i=0; i<n; i++)
            cin>>stall[i];
        sort(stall, stall+n);
        cout<<search(0, 1000000000)<<"\n";
        //cout<<c<<"#\n";
    }
    return 0;
}
/*
3
2 2
1
2
2 2
1
1
10 2
1
2
3
4
5
6
7
8
9
10

1
5 3
1
2
8
4
9
*/
