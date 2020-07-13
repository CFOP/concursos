#include <bits/stdc++.h>

using namespace std;
bool notPrime[10005];
bool visited[10005];
int m=-1;

int change(int n, int a, int b){ //a digit to b from n
    int digit=n/pow(10, 4-a);
    digit%=10;
    //cout<<digit<<" ";
    n=n-(int)(digit*pow(10, 4-a));
    //cout<<digit<<" ";
    n+=pow(10, 4-a)*b;
    return n;
}

int get(int n, int a){//a element from n
    int digit=n/pow(10, 4-a);
    digit%=10;
    return digit;
}

void bfs(int from, int to, int s){
    queue<tuple<int, int, int>> que;
    que.push(make_tuple(from, to, s));
    while(true){
        from = get<0>(que.front());
        to = get<1>(que.front());
        s = get<2>(que.front());
        que.pop();
        if(from<1000)continue;
        if(visited[from])continue;
        visited[from]=true;
        if(notPrime[from])
            continue;
        cout<<from<<"\n";
        if(from==to){
            m = min(s, m);
            if(m==-1)m=s;
            return;
        }
        //cout<<"v";
        for(int j=1; j<=4; j++)
            for(int i=0; i<=9; i++){
                if(visited[change(from, j, i)])continue;
                que.push(make_tuple(change(from, j, i), to, s+1));
                //cout<<change(from, j, i)<<"\n";
            }
        //return 0;
    }
}

int main(){
    int n;
    int a, b;
    //cout<<change(1733, 1, 3);
    cin>>n;

    //criba
    for(int i=2; i<10000; i++){
        if(notPrime[i])continue;
        for(int j=i*2; j<10000; j+=i)
            notPrime[j]=true;
    }
    //cout<<notPrime[1733];


    while(n--){
        cin>>a>>b;
        if(notPrime[a]||notPrime[b]){
            cout<<"Impossible\n";
        }
        m=-1;
        bfs(a, b, 0);

        cout<<m<<"\n";
        for(int i=0; i<10005; i++)
            visited[i]=false;
    }

    return 0;
}
