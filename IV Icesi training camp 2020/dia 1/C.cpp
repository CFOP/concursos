#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> operations;
deque<int> d;

void operation(){
    int a, b;
    a = d.front();
    d.pop_front();
    b = d.front();
    d.pop_front();
    //cout<<a<<" "<<b<<"\n";
    operations.push_back(make_pair(a, b));
    if(a<b)swap(a, b);
    d.push_front(a);
    d.push_back(b);


}

int main(){
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        d.push_back(a);
    }
    for(int i=0; i<n*2; i++)
        operation();

    unsigned long long m;
    if(q==0)
        cout<<"\n";
    for(int i=0; i<q; i++){
        cin>>m;
        if(m<n){
            cout<<operations[m-1].first<<" "<<operations[m-1].second<<"\n";
        }
        else{
            m%=n-1;
            cout<<operations[m+n-2].first<<" "<<operations[m+n-2].second<<"\n";
        }
    }
    return 0;
}

/*
5 3
1 2 3 4 5
1
2
10

5 2 3 4 1

4 10
1 2 3 4

4 1 2 3

1 2 3 4 5

5 1 2 3 4

5 1 2 3 4
*/
