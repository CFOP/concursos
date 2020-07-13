#include <bits/stdc++.h>
#define YEARS 1000005

using namespace std;
int total[YEARS];
int pope[100000];
int y, p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>y>>p){
        for(int i=0; i<YEARS; i++)
            total[i]=0;
        for(int i=0; i<p; i++)
            cin>>pope[i];
        sort(pope, pope+p);
        for(int i=1, j=0; i<YEARS; i++){
            total[i]=total[i-1];
            while(i==pope[j]){
                j++;
                total[i]++;
            }
        }
        int m = 0;
        int a, b;
        /*for(int i=0; i<40; i++){
            cout<<i<<"\t"<<total[i]<<"\n";
        }*/
        for(int i=1; i<=YEARS-y+1; i++){
            if(m<total[i+y-1]-total[i-1]){
                m=total[i+y-1]-total[i-1];
                b=i+y-1;
                a=i;
            }
        }
        /*for(int i=0; i<p; i++)
            cout<<pope[i]<<"\n";
        cout<<a<<" "<<b<<"\n";*/
        cout<<m<<" ";
        for(int i=0; i<p; i++){
            if(pope[i]>=a){
                cout<<pope[i]<<" ";
                break;
            }
        }
        for(int i=p-1; i>=0; i--){
            if(pope[i]<=b){
                cout<<pope[i]<<"\n";
                break;
            }
        }
    }
}

/*
1 2 3 4 5 6 7 8 9 10
*/
