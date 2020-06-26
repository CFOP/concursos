#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

char maze[MAX][MAX];
int area[MAX][MAX];
int R, C;
int areas;

#define ARRIBA 0
#define ABAJO 1
#define DERECHA 2
#define IZQUIERDA 3


void marcar(int y, int x, int marca, int dir){


    if(x<0 || y<0)return;
    if(x>C+1 || y>R+1)return;
    /*for(int i=0; i<=R+1; i++){
        for(int j=0; j<=C+1; j++){
            if(i!=y||j!=x)cout<<area[i][j];
            else cout<<"o";
        }
        cout<<"\n";
    }
    //cout<<"v";
    getchar();*/

    //if(y)

    if(maze[y][x]=='.'){
        if(area[y][x])return;
        area[y][x]=3;
        marcar(y, x+1, marca, IZQUIERDA); //derecha
        marcar(y-1, x, marca, ABAJO); //arriba
        marcar(y, x-1, marca, DERECHA); //izquierda
        marcar(y+1, x, marca, ARRIBA); //abajo
    }
    if(maze[y][x]=='/'){

        if(dir==ABAJO || dir==DERECHA){
                if(area[y][x]==1 || area[y][x]==3)return;
                area[y][x]+=1;
                marcar(y, x+1, marca, IZQUIERDA); //derecha
                marcar(y+1, x, marca, ARRIBA); //abajo
        }
        if(dir==ARRIBA || dir==IZQUIERDA){
            if(area[y][x]==2 || area[y][x]==3)return;
            area[y][x]+=2;
            marcar(y, x-1, marca, DERECHA); //izquierda
            marcar(y-1, x, marca, ABAJO); //arriba
        }

    }
    if(maze[y][x]=='\\'){

        if(dir==ARRIBA || dir==DERECHA){
            if(area[y][x]==2 || area[y][x]==3)return;
            area[y][x]+=2;
            marcar(y, x+1, marca, IZQUIERDA); //derecha
            marcar(y-1, x, marca, ABAJO); //arriba
        }
        if(dir==ABAJO || dir==IZQUIERDA){
            if(area[y][x]==1 || area[y][x]==3)return;
            area[y][x]+=1;
            marcar(y, x-1, marca, DERECHA); //izquierda
            marcar(y+1, x, marca, ARRIBA); //abajo
        }

    }
}

int main(){
    memset(maze, '.', sizeof(maze));
    cin>>R>>C;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++){
            cin>>maze[i][j];
        }
    cin.clear();
    getchar();
    marcar(0, 0, 1, ARRIBA);
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(area[i][j]==3)continue;
            if(!area[i][j])
                marcar(i, j, ++areas, ABAJO);
            if(maze[i][j]==1)
                marcar(i, j, ++areas, ARRIBA);
            if(maze[i][j]==2)
                marcar(i, j, ++areas, ABAJO);

        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<area[i][j];
        }
        cout<<"\n";
    }
    cout<<areas<<"\n";
    return 0;
}
/*
4 8
../\....
./\/\...
.\/\/\..
....\/..

8 8
.../\...
../..\..
././\.\.
/..\/..\
\....../
.\..../.
..\../..
...\/...

2 4
////
////

*/
