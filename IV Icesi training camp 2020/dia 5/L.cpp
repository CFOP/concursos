#include <bits/stdc++.h>
#define MAX 300005

using namespace std;
int n, m;

int derrotador[MAX];

struct st{
    st *left, *right;
    int derrotador;
    int l, r, m;

    st(int l, int r): derrotador(0), l(l), r(r){
        if(l!=r){
            m=(l+r)/2;
            left = new st(l, m);
            right = new st(m+1, r);
        }
    }

    void update(int a, int b, int derrotador){
        //cout<<l<<" "<<r<<"\n";
        if(a > r || b < l) return;
        if(derrotador!=0)return;
        if(l==r)
            this->derrotador = derrotador;
        else {
            //
            left->update(a, b, derrotador);
            right->update(a, b, derrotador);
            //if(a >= l && b<=r ) this->derrotador = derrotador;
            //if(l == 2 && r ==3)cout<<left->value<<" "<<right->value<<" "<<isOr<<"#\n";
            //cout<<left->value<<" "<<right->value<<" "<<value<<"\n";
        }
        //cout<<value<<"\n";

    }

    int get(int pos){
        //cout<<l<<" "<<r<<"\n";
        if(l==r)
            return derrotador;
        else {
            if(pos <= m)
                return left->get(pos);
            else return right->get(pos);
        }

    }

};

int main(){
    cin>>n>>m;
    st tree(0, n-1);
    //cout<< (1<<n) << "\n\n";
    for(int i=0; i<m; i++){
        int l, r, x; cin>>l>>r>>x;
        tree.update(l-1, r-1, x);
    }
    for(int i=0; i<n; i++){
        cout<<tree.get(i)<<" ";
    }
    return 0;
}

