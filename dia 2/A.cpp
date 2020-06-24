#include <bits/stdc++.h>

using namespace std;
int n, q;
vector <float> marble;

int binary(float n, int first, int last){
    if(marble[first]==n)
            return first;
    if(first>last){
        if(marble[last]==n)
            return last;
        return -1;
    }
    int middle = (first+last)/2;
    if(marble[middle]>=n)
        return binary(n, first, middle-1);
    return binary(n, middle+1, last);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int j=1;
    for(cin>>n>>q; n || q; cin>>n>>q){
        marble.clear();
        for(int i=0; i<n; i++){
            marble.push_back(0);
            cin>>marble[i];
        }
        sort(marble.begin(), marble.end());
        cout<<"CASE# "<<j<<":\n";
        for(int i=0; i<q; i++){
            float p;
            cin>>p;
            int r = binary(p, 0, marble.size()-1);
            if(r==-1){
                cout<<p<<" not found\n";
            }
            else {
                cout<<p<<" found at "<<r+1<<"\n";
            }
        }
        j++;
    }
    return 0;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10000
10000
1
-1
2
0
1 1
1
1
3 2
1 2 3
1
3
0 0

3 3
3 2 1
1
2
3
0 0

11 3
1 2 3 4 5 6 7 8 9 10 11
2
10
6
0 0

20 22
20 19 18 17 16 16 14 13 12 11 10 9 8 7 6 5 4 3 2 1
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
11
12
13
14
15
16
17
18
19
20
0
21
0 0
21 22
20 19 18 17 16 21 16 14 13 12 11 10 9 8 7 6 5 4 3 2 1
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
11
12
13
14
15
16
17
18
19
20
0
21
0 0

21 1
20 19 18 17 16 21 16 14 13 12 11 10 9 8 7 6 5 4 3 2 1
16
0 0

21 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 15 17 18 19 20 21
15
0 0
*/
