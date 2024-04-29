#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> adjMatrix, int src, int vertices) {
  vector<bool> visited(vertices, false);
  vector<int> color(vertices, -1);
  queue<int> q;

  visited[src] = true;
  color[src] = 0;
  q.push(src);

  while(!q.empty()) {
    int current = q.front();
    q.pop();
    cout<<"Current Node: "<<current<<endl;

    for(int neigh=0; neigh<adjMatrix.size(); neigh++) {
      
      if(adjMatrix[current][neigh] && !visited[neigh]) {
        visited[neigh] = true;
        color[neigh] = !color[current];
        q.push(neigh);
      }
      else if(adjMatrix[current][neigh] && neigh != current) {
        cout<<"Color neigh: "<<neigh<<" "<<color[neigh]<<" Color curr: "<<current<<" "<<color[current]<<endl;
        if(color[neigh] == color[current]) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int vertices, temp, src;
  cout<<"Enter number of vertices: ";
  // cin>>vertices;
  vertices = 5;

  vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

  cout<<"Enter edges:"<<endl;
  // for(int i=0; i<vertices; i++){
  //   for(int j=0; j<vertices; j++){
  //     cin>>temp;
  //     adjMatrix[i][j] = temp;
  //   }
  // }
  // adjMatrix = { // bipartite
  //   {0,1,1,1,0},
  //   {1,0,0,0,1},
  //   {1,0,0,0,1},
  //   {1,0,0,0,0},
  //   {0,1,1,0,0}
  // };
  adjMatrix = { // def bipartite
    {0,1,0,0,0},
    {1,0,1,0,0},
    {0,1,0,1,0},
    {0,0,1,0,1},
    {0,0,0,1,0}
  };
  // adjMatrix = { // mine
  //   {0,1,1,0,0},
  //   {1,0,1,1,1},
  //   {1,1,0,1,0},
  //   {0,1,1,0,1},
  //   {0,1,0,1,0}
  // };

  cout<<"Enter source vertex: ";
  // cin>>src;
  src = 0;

  // BFS(adjMatrix, visited, src);
  if(isBipartite(adjMatrix, visited, color, src)) {
    cout<<"Yes Bipartite"<<endl;
  } else {
    cout<<"Not Bipartite"<<endl;
  }
}

// NOT DONE
