#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool verify(string s){
    stack <char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]==']' || s[i]==')'){
            if(st.empty())
                return false;
            if(s[i]==']'){
                if(st.top()=='(') return false;
                st.pop();
            }
            if(s[i]==')'){
                if(st.top()=='[') return false;
                st.pop();
            }
        }
        else {
            st.push(s[i]);
        }
    }
    return st.empty();
}

int main(){
    cin>>n;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        if(verify(s))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

/*
5
(((((
)))))
[]
([))
([])
*/
