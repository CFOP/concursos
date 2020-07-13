#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n;
int permutation[MAX];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>permutation[i];

    }
    return 0;
}
/*
2
3
3 2 1
4
1 3 4 2

|s1−s2|+|s2−s3|+…+|sk−1−sk|

1,2,3
|1 - 3| = 2
|1 - 2| + |2- 3| = 1  + 1 = 2

1 3 4 2
|1 - 2| = 1
2 + 1 + 2 = 5
*/
