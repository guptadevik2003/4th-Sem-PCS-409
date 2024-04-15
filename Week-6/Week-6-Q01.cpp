#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>> adj, int node){
  stack<int> stack;
  vector<int> visited;
}

int main(){
  int v, temp;
  // cout<<"Enter number of vertices: ";
  // cin>>v;
  v = 5
  
  vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

  // cout<<"Enter edges:"<<endl;
  // for(int i=0; i<v; i++){
  //   for(int j=0; j<v; j++){
  //     cin>>temp;
  //     adjMatrix[i][j] = temp;
  //   }
  // }
  adjMatrix = {
    {0,1,1,0,0},
    {1,0,1,1,1},
    {1,1,0,1,0},
    {0,1,1,0,1},
    {0,1,0,1,0},
  };

}

// 
