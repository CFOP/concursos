#include <bits/stdc++.h>
using namespace std;
int n, m;

struct st{
    st *left, *right;
    bool isOr;
    unsigned int value;
    int l, r, m;

    st(bool isOr, int l, int r): value(value), isOr(isOr), l(l), r(r){
        if(l!=r){
            m=(l+r)/2;
            left = new st(!isOr, l, m);
            right = new st(!isOr, m+1, r);
        }
    }

    void update(int pos, int v){
        //cout<<l<<" "<<r<<"\n";
        if(l==r)
            value = v;
        else {
            if(pos <= m)
                left->update(pos, v);
            else right->update(pos, v);
            if(isOr)
                value = left->value | right->value;
            else
                value = left->value ^ right->value;
            //if(l == 2 && r ==3)cout<<left->value<<" "<<right->value<<" "<<isOr<<"#\n";
            //cout<<left->value<<" "<<right->value<<" "<<value<<"\n";
        }
        //cout<<value<<"\n";

    }

    int get(int pos){
        //cout<<l<<" "<<r<<"\n";
        if(l==r)
            return value;
        else {
            if(pos <= m)
                return left->get(pos);
            else return right->get(pos);
        }

    }

    void calculate(){
        //cout<<l<<" "<<r<<"\n";
        if(l!=r) {
            left->calculate();
            right->calculate();
            if(isOr)
                value = left->value | right->value;
            else
                value = left->value ^ right->value;
            //cout<<left->value<<" "<<right->value<<" "<<value<<"\n";
        }
    }

};

int main(){
    cin>>n>>m;
    st tree(n%2, 0, (1<<n)-1);
    //cout<< (1<<n) << "\n\n";
    for(int i=0; i<1<<n; i++){
        int a; cin>>a;
        tree.update(i, a);
    }
    tree.calculate();
    for(int i=0; i<m; i++){
        int p, b; cin>>p>>b;//cout<<"\n";
        tree.update(p-1, b);//cout<<"\n";
        cout<<tree.value<<"\n";
    }
    return 0;
}
