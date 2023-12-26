#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges,int n,int sv,bool* visited){
    queue<int> pending;
    pending.push(sv);
    visited[sv]=true;
    while(!pending.empty()){
        cout<<pending.front()<<endl;
        for(int i=0;i<n;i++){
            if(i==pending.front() || visited[i]){
                continue;
            }
            if(edges[pending.front()][i]==1){
              pending.push(i);
              visited[i]=true;
            }
        }
        pending.pop();
    }
}

void BFS(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

int main(){
   int n,e;
   cin>>n>>e;
   int** edges=new int*[n];
   for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++){
        edges[i][j]=0;
    }
   }
   for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
   }
   bool* visited=new bool[n];
   for(int i=0;i<n;i++){
    visited[i]=false;
   }
   BFS(edges,n);
}