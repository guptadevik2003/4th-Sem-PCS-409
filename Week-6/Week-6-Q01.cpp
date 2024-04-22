#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> adjMatrix, vector<bool> &visited, int vertex) {
  visited[vertex] = true;
  
  for(int neigh=0; neigh<adjMatrix.size(); neigh++) {
    if(adjMatrix[vertex][neigh] && !visited[neigh]) {
      DFS(adjMatrix, visited, neigh);
    }
  }
}

int main() {
  int vertices, temp, src, dest;
  cout<<"Enter number of vertices: ";
  cin>>vertices;
  
  vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
  vector<bool> visited(vertices, false);

  cout<<"Enter edges:"<<endl;
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++){
      cin>>temp;
      adjMatrix[i][j] = temp;
    }
  }
  
  cout<<"Enter Source vertex: ";
  cin>>src;
  
  cout<<"Enter Destination vertex: ";
  cin>>dest;

  DFS(adjMatrix, visited, src);
  
  if(visited[dest]) {
    cout<<"Yes Path Exists"<<endl;
  } else {
    cout<<"No Such Path Exists"<<endl;
  }
}

// DONE
