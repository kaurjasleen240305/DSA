#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited){
     cout<<sv<<endl;
     visited[sv]=true;
     for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
     }
}

//FOR UNCONNECTED GRAPH
void DFS(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

//HAS PATH
bool haspath(int** edges,int n,int sv,int ev,bool* visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1){
            if(i==sv){
                continue;
            }
            if(visited[i]==true){
                continue;
            }
            if(i==ev){
                return true;
            }
        }
    }
    return false;
}

vector<int>* getPathHelper(int** edges,int n,int sv,int ev,bool* visited){
    if(sv==ev){
        vector<int>* output=new vector<int>();
        output->push_back(sv);
        return output;
    }
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] && !visited[i]){
            vector<int>* smalloutput=getPathHelper(edges,n,i,ev,visited);
            if(smaloutput!=NULL){
                smalloutput->push_back(sv);
                return smalloutput;
            }
        }
    }
    return null;
}
vector<int>* getPath(int** edges,int n,int sv,int ev){
   bool* visited=new bool[n];
   for(int i=0;i<n;i++){
    visited[i]=false;
   }
   vector<int>* output=getPathHelper(edges,n,sv,ev,visited);
   delete[] visited;
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
   int sv,ev;
   cout<<"GIVE ST AND EV"<<endl;
   cin>>sv>>ev;
   cout<<haspath(edges,n,sv,ev,visited);
}